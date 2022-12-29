#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

#include "header.h"
#include "BST.h"
#include "parsing.h"

int main() 
{ 
    TreeNode *tN = NULL; 
    
    tN = parseIt(); // opens the input file, then puts all the words into a BST
    
    inorder(tN); // performs the inorder traversal of the BST, then creates the output file "WORDS.txt" that will contain the words arranged in alphabetical order with its frequency count
    
    tN = destroy(tN); // destroys all the nodes of the BST
   
    return 0; 
} 
