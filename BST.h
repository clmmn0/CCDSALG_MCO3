// C program to demonstrate insert operation in binary search tree. 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

TreeNode *create(String new) 
{ 
    TreeNode *tN =  (TreeNode*)malloc(sizeof(TreeNode)); // memory is allocated to create a node which will be part of the tree
    strcpy(tN->word, new); // the new word is put into the node
    tN->count = 1;
    tN->left = NULL;
	tN->right = NULL; 
	
    return tN; 
} 

/* 
This function checks if the new word already has a node in the tree.
This function returns the updated node in case the new word already exists in the tree.
*/
TreeNode* search(TreeNode* tN, String new, int *val) 
{ 
	*val = 0; // 0 means the new word was not found. 1 means the new word was found.
	
    if(tN != NULL){ 
    	if (strcmpi(tN->word, new) == 0){ // checks if the new word and the word in the current node is the same
    		(tN->count)++; // 1 is added to the frequency count of the same word found in the tree
    		*val = 1; // val becomes 1 to indicate that the new word already has a node in the tree
    		return tN;
		}
		
    	else{
    		if (strcmpi(tN->word, new) < 0 ) // If the new word is greater in value than the word in the current node, it searches again, but the new node is the node found at the right of the current node.
    			search(tN->right, new, &*val); 
	
			else
    			search(tN->left, new, &*val); // Else, the new node for the search() function is the node on the left of the current node.
		}
	}
	
	return tN;
} 

// This function inserts the new word into a node in the tree. It returns the updated tree.   
TreeNode* insert(TreeNode* tN, String new) 
{ 
    if (tN == NULL) 
		tN = create(new); // creates a new node in the tree
  	
  	else{
  		if (strcmpi(new, tN->word) < 0) // This if-else statement calls the insert function until the word reaches its right place in the tree.
   	    	tN->left  = insert(tN->left, new); 
 		else
      		tN->right = insert(tN->right, new);        	
    }
  
    return tN; 
} 

//This function creates a new .txt file "WORDS.txt" which will contain the words arranged in alphabetical order together with their frequency count.
void printList(TreeNode *tN)
{
	FILE* fp;
	
	fp = fopen("WORDS.txt", "a");
	fprintf(fp, "%s %d\n", tN->word, tN->count);
	fclose(fp);
}

// This function performs the inorder traversal of the BST   
void inorder(TreeNode *tN) 
{ 
    if (tN != NULL) { 
        inorder(tN->left); 
        printList(tN); // it calls the printList function to put the word into the output file
        inorder(tN->right); 
    } 
} 

// This function destroys all the nodes in the tree
TreeNode* destroy(TreeNode* tN)  
{ 		
    if (tN != NULL){
    	destroy(tN->left); 
	   	destroy(tN->right); 
		free(tN); // deallocates the memory of the node  
		tN = NULL;	
	}
	
	return tN;	
}  


