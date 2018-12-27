// Here we find the middle node of list and make it root of the tree to be constructed
// Recursively we do the same for left half and right half of the linked list
// Time complexity: O(nlogn) where n is the number of nodes in Linked List

#include <stdio.h> 
#include <stdlib.h> 

/* Link list node */
struct LNode 
{ 
	int data; 
	struct LNode* next; 
}; 

/* A Binary Tree node */
struct TNode 
{ 
	int data; 
	struct TNode* left; 
	struct TNode* right; 
}; 

/* Helper function that allocates a new tree node with the 
given data and NULL left and right pointers. */
struct TNode* newNode(int data) 
{ 
	struct TNode* node = (struct TNode*) 
						malloc(sizeof(struct TNode)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return node; 
} 

/* UTILITY FUNCTIONS */

/* A utility function that returns count of nodes in a given Linked List */
int countLNodes(struct LNode *head) 
{ 
	int count = 0; 
	struct LNode *temp = head; 
	while(temp) 
	{ 
		temp = temp->next; 
		count++; 
	} 
	return count; 
} 

/* Function to insert a node at the beginning of the linked list */
void push(struct LNode** head_ref, int new_data) 
{ 
	/* allocate node */
	struct LNode* new_node = 
		(struct LNode*) malloc(sizeof(struct LNode)); 
	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print nodes in a given linked list */
void printList(struct LNode *node) 
{ 
	while(node != NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
	} 
} 


/* A utility function to print preorder traversal of BST */
void preOrder(struct TNode* node) 
{ 
	if (node == NULL) 
		return; 
	printf("%d ", node->data); 
	preOrder(node->left); 
	preOrder(node->right); 
} 

/* A function that constructs Balanced Binary Search Tree from a sorted linked list */
struct TNode* sortedLLToBST(struct LNode *head, int start, int end) 
{ 
	
	// Base Case
	if (start > end) 
	return NULL; 
    
    struct LNode *temp = head;
	
	// Get the middle element and make it root 
	int mid = (start + end)/2; 
	for (int count = 0; count != mid; count++)
	    temp = temp->next;
	struct TNode *root = newNode(temp->data); 

	// Recursively construct the left subtree and make it 
	// child of root
	root->left = sortedLLToBST(head, start, mid-1); 

	// Recursively construct the right subtree and make it 
	// right child of root
	root->right = sortedLLToBST(head, mid+1, end); 

	return root; 
}


/* Driver program to test above functions*/
int main() 
{ 
	/* Start with the empty list */
	struct LNode* head = NULL; 

	/* Let us create a sorted linked list to test the functions 
	Created linked list will be 1->2->3->4->5->6->7->8->9 */
	push(&head, 9);
	push(&head, 8);
	push(&head, 7); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 

	printf("Given Sorted Linked List\n");
	printList(head);
	
	int count = countLNodes(head);
	/* Convert List to BST */
	struct TNode *root = sortedLLToBST(head, 0, count-1); 
	printf("\nPreOrder Traversal of constructed Balanced BST\n"); 
	preOrder(root); 
	printf("\n");
	return 0; 
} 

