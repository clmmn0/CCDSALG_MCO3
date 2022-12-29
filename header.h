#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

typedef char String[51];

// struct for the node of a certain word in the BST
struct node 
{ 
    String word; // the word that is found in the node
    int count; // frequency count of the word inside this node
    struct node *left; // pointer to the node on the left of this current node
	struct node *right; // pointer to the node on the right of this current node
}; 
 
typedef struct node TreeNode;
