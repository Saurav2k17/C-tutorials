// Deletes a Binary Tree by freeing the memory
// Time Complexity: O(n) where n is number of nodes in the binary tree

#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers */
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*) 
						malloc(sizeof(struct node)); 

	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 

/* We are deleting the tree in this function */
void _deleteTree(struct node* node) 
{ 
	if (node == NULL) return; 

	/* first delete both subtrees */
	_deleteTree(node->left); 
	_deleteTree(node->right); 

	/* then delete the node */
	printf("\n Deleting node: %d", node->data); 
	free(node); 
} 

/* Deletes the tree and sets the root as NULL */
void deleteTree(struct node** node_ref) 
{ 
	_deleteTree(*node_ref); 
	*node_ref = NULL; 
} 

/* Driver program to test deleteTree function */
int main() 
{ 
	/* Let us create the following binary tree 
			  1 
		    /   \ 
		   2    3 
		  / \  / \
	     4  5 6  7
	*/

	struct node *root  = newNode(1); 
	root->left		   = newNode(2); 
	root->right		   = newNode(3); 
	root->left->left   = newNode(4); 
	root->left->right  = newNode(5); 
	root->right->left  = newNode(6); 
	root->right->right = newNode(7); 

	// Note that we pass the address of root here 
	deleteTree(&root); 
	printf("\n Tree deleted \n"); 
	return 0; 
} 

