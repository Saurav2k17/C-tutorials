// Sorted array to Balanced BST
// Example:
/* Input:  Array {1, 2, 3}
Output: A Balanced BST
     2
    / \
   1   3 
*/
// Construction of Balanced BST from sorted array in O(n) time is simpler
// as we can get the middle element in O(1) time.
// Time Complexity: O(n)
// Following is the recurrence relation for sortedArrayToBST():
// T(n) = 2T(n/2) + C


#include <stdio.h> 
#include <stdlib.h> 

/* A Binary Tree node */
struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers */
struct Node* newNode(int data) 
{ 
	struct Node* node = (struct Node*) 
						malloc(sizeof(struct Node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return node; 
}

/* A function that constructs Balanced Binary Search Tree from a sorted array */
struct Node* sortedArrayToBST(int arr[], int start, int end) 
{ 
	/* Base Case */
	if (start > end) 
	return NULL; 

	/* Get the middle element and make it root */
	int mid = (start + end)/2; 
	struct Node *root = newNode(arr[mid]); 

	/* Recursively construct the left subtree and make it 
	left child of root */
	root->left = sortedArrayToBST(arr, start, mid-1); 

	/* Recursively construct the right subtree and make it 
	right child of root */
	root->right = sortedArrayToBST(arr, mid+1, end); 

	return root; 
} 


/* A utility function to print preorder traversal of BST */
void preOrder(struct Node* node) 
{ 
	if (node != NULL) 
	{ 
		printf("%d ", node->data); 
		preOrder(node->left); 
		preOrder(node->right); 
	}
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 6, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	/* Convert List to BST */
	struct Node *root = sortedArrayToBST(arr, 0, n-1); 
	printf("PreOrder Traversal of constructed BST\n"); 
	preOrder(root); 
	printf("\n");
	return 0; 
} 

