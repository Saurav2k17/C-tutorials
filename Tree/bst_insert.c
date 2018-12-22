// Insert operation in binary search tree 
// Worst case time complexity of search and insert operations is O(h) where h is height of BST
// In worst case, we may have to travel from root to the deepest leaf node
// The height of a skewed tree may become 'n' and the time complexity of search and insert operation may become O(n)
// There must be no duplicate nodes
// Inorder traversal of BST always produces sorted output
// In-order, Pre-order, and Post-order traversals are Depth-First traversals
// The complexity of a Depth First Traversal is O(n + m), where n is the number of nodes and m is the number of edges
// Since the number of edges that can originate from a node is limited to 2 in the case of a Binary Tree, 
// the maximum number of total edges in a Binary Tree is n-1, where n is the total number of nodes
// The complexity then becomes O(n + n-1), which is O(n)

#include <stdio.h> 
#include <stdlib.h> 

struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

/* Utility function to create a new BST node */
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

/* Utility function to do inorder traversal of BST */
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d\n", root->key); 
		inorder(root->right); 
	} 
} 

/* Utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 

// Driver Program to test above functions 
int main() 
{ 
	/* Let us create the following BST 
			 50 
		   /   \ 
		 30    70 
		/ \   / \ 
	   20 40 60 80 
	*/
	struct node *root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 

	/* print inorder traversal of the BST */
	inorder(root); 

	return 0; 
} 

