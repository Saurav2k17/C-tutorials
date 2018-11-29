// Merge Sort for linked lists
// The slow random-access performance of a linked list makes some other algorithms 
// (such as quicksort) perform poorly and others (such as heapsort) completely impossible

#include <stdio.h> 
#include <stdlib.h> 

/* Defining Node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

/* Function Prototypes */
struct Node* mergeList(struct Node* a, struct Node* b); 
void splitList(struct Node* source, struct Node** frontRef, struct Node** backRef); 

/* Sorts the linked list by changing next pointers (not data) */
void MergeSort(struct Node** headRef) 
{ 
	struct Node* head = *headRef; 
	struct Node* a; 
	struct Node* b; 

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) 
	{ 
		return; 
	} 

	/* Split the list beginning with head into 'a' and 'b' sublists */
	splitList(head, &a, &b); 

	/* Recursively sort the sublists until the sublist contains only one element */
	MergeSort(&a); 
	MergeSort(&b); 

	/* answer = merge the two sorted lists together */
	*headRef = mergeList(a, b); 
} 

/* Merge the two sorted lists */
struct Node* mergeList(struct Node* a, struct Node* b) 
{ 
	struct Node* result = NULL; 

	/* Base cases */
	if (a == NULL) 
		return(b); 
	else if (b==NULL) 
		return(a); 

	/* Pick either a or b, and recur */
	if (a->data <= b->data) 
	{ 
		result = a; 
		result->next = mergeList(a->next, b); 
	} 
	else
	{ 
		result = b; 
		result->next = mergeList(a, b->next); 
	} 
	return(result); 
} 

// Splits the nodes of the given list into front and back halves,
// and returns the two lists using the reference parameters.
// If the length is odd, the extra node should go in the front list.
// Uses the fast/slow pointer strategy.
void splitList(struct Node* source, struct Node** frontRef, struct Node** backRef) 
{ 
	struct Node* slow; 
	struct Node* fast; 
	slow = source; 
	fast = source->next; 

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) 
	{ 
		fast = fast->next; 
		if (fast != NULL) 
		{ 
			slow = slow->next; 
			fast = fast->next; 
		} 
	} 

	/* 'slow' is before the midpoint in the list, so split it in two at that point. */
	*frontRef = source; 
	*backRef = slow->next; 
	slow->next = NULL; 
} 

/* Function to print nodes in a given linked list */
void printList(struct Node* node) 
{ 
	while(node!=NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
	}
	printf("\n"); 
} 

/* Function to insert a node at the beginging of the linked list */
void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Driver program to test above functions */
int main() 
{ 
	/* Start with the empty list */
	struct Node* a = NULL; 

	/* Let us create an unsorted linked list to test the functions 
	Created lists shall be a: 2->3->20->5->10->15 */
	push(&a, 25); 
	push(&a, 20); 
	push(&a, 15); 
	push(&a, 30); 
	push(&a, 13); 
	push(&a, 22); 

	printf("Given Linked List is: \n"); 
	printList(a);

	/* Sort the above created Linked List */
	MergeSort(&a); 

	printf("Sorted Linked List is: \n"); 
	printList(a);		 
 
	return 0; 
} 

