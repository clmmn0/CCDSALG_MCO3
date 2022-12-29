#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* toLowerCase(char* new)
{
	int i;
	
	for(i = 0; i < strlen(new); i++){ // turns all the letters of the word into lower case
 		if(new[i] >= 65 && new[i] <= 90)
    		new[i] += 32;
	}
	
	return new;
}

// This function deletes unnecessary punctuations found at the beginning and end of a word
char* deletePunctuations(char* new)
{
	int i = 0;
	
	while(!((new[0] >= 'A' && new[0]) || (new[0] >= 'a' && new[0] <= 'z'))){ // deletes unnecessary punctuations found at the beginning of the word
   		for(i = 0; i < strlen(new); i++){
   			new[i] = new[i+1];
		}	
	}
	
	while(!((new[strlen(new) - 1] >= 'A' && new[strlen(new) - 1] <= 'Z') || (new[strlen(new) - 1] >= 'a' && new[strlen(new) - 1] <= 'z'))){ // deletes unnecessary punctuations found at the end of the word
        new[strlen(new) - 1] = '\0';
    }
	
	return new;
}

// This function reads the given text file, deletes unnecessary punctuations, and creates a BST
TreeNode* parseIt()
{	
	TreeNode *tN = NULL; 
    FILE *fp;
    String fileName, new;
    int val = 0;

    printf ("Input filename: "); // user enters name of text file
    scanf("%s", fileName);

    fp = fopen(fileName, "r");

    if (fp != NULL) {
        while ( fscanf(fp, "%s", new) != EOF )
        {   
        	strcpy(new, deletePunctuations(new)); // deletes unnecessary punctuations
        	
            if(strlen(new) >= 3) // checks if the word contains at least 3 letters. If not, then the new word is not inserted into the tree.
			{ 
    			strcpy(new, toLowerCase(new)); // turns all the letters of the word into lower case

    			search(tN, new, &val); // checks if the new word already has a node in the tree. If yes, then the frequency count of the same word in the tree increases by 1, and the insert method is cancelled.
    		
    			if(val != 1) // If val != 1, then it means that the word does not yet exist in the tree. Thus, it will continue with the insert method.
					tN = insert(tN, new); // inserts the new word into the tree		
			}
        }

        fclose(fp);
    }
    
    else {  			
        fprintf(stderr, "%s not found.\n", fileName);	// stderr = Standard Error
		exit(1);		
    }

    return tN;
}

