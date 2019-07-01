// Swap kth node from beginning with the kth node from end in a Linked List
// Swapping of data is not allowed, only pointers should be changed
// Let X be the kth node from beginning and Y be the kth node from end
// Following are the interesting cases that must be handled:
// 1) Y is next to X
// 2) X is next to Y
// 3) X and Y are same
// 4) X and Y don’t exist (i.e. k is more than the number of nodes in the linked list)

#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct Node
{
	int data;
	struct Node* next;
};

struct Node* next_node; // updates the next node

/* Function for calculating the length of the linked list */
int countNodes(struct Node *node)
{
	int count = 0;
	while(node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}

/* Function for swapping the kth nodes from both ends of the linked list */
void swapkth(struct Node **head_ref, int k)
{
	// Count the number of nodes in the linked list
	int n = countNodes(*head_ref);

	// Check if k is valid
	if(n < k)
		return; // if k is more than the number of nodes, then we simply return

	// If x (kth node from start) and y(kth node from end) are same
	if(2*k - 1 == n)
		return; // no need to perform swap operation

	// Find the kth node from the beginning of linked list. We also find
	// the previous of kth node, because we need to update next pointer of
	// the previous of kth node
	struct Node *x = *head_ref;
	struct Node *x_prev = NULL;
	for(int i = 1; i < k; i++)
	{
		x_prev = x;
		x = x->next;
	}

	// Similarly, we find the kth node from the end and its previous node as well.
	// kth node from the end is (n-k+1)th node from the beginning of the linked list
	struct Node *y = *head_ref;
	struct Node *y_prev = NULL;
	for(int i = 1; i < n-k+1; i++)
	{
		y_prev = y;
		y = y->next;
	}

	// If x_prev exists, then new next of it will be y. Consider the case
	// when y->next is x, in this case, x_prev and y are same. So the statement
	// "x_prev->next = y" creates a self loop. This self loop will be broken
	// when we change y->next.
	// e.g., 1->2->3->4->5->6 (4th node from the beginning and end are 4 and 3 respectively)
	// In the above example, x=4 and y=3. y->next=4 (which is x) and x_prev=3 (which is y).
	// So x_prev->next=y leads to 3->next=3 which is a self loop.
	if(x_prev)
		x_prev->next = y;

	// Same thing applies to y_prev
	if(y_prev)
		y_prev->next = x;

	// Swap next pointers of x and y. These statements also break self
	// loop if x->next is y or y->next is x
	struct Node *temp = x->next;
	x->next = y->next;
	y->next = temp;

	// Change the head pointer when k is 1 or n
	if(k == 1)
		*head_ref = y;
	if(k == n)
		*head_ref = x;
}

/* Function to insert a new node at the end of linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	/* put in the data  */
	new_node->data = new_data;
	new_node->next = NULL;

	if(*head_ref == NULL)
	{
		(*head_ref) = new_node;
	}
	else
	{
		next_node->next = new_node;
	}

	next_node = new_node;
}

/* Function to print a given linked list */
void printList(struct Node *ptr)
{
	while(ptr != NULL)
	{
		(ptr->next != NULL)? printf("%d->", ptr->data) : printf("%d", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

/* Driver program to test above functions */
int main()
{
	/* start with the empty list */
	struct Node* head = NULL;
	int num_nodes;
	int node_val;

	printf("How many nodes do you want in the linked list? ");
	scanf("%d", &num_nodes);

	if(num_nodes <= 0)
	{
		printf("You entered an invalid number ! Program terminated\n");
		return 0;
	}
	
	printf("Enter the data value of the %d nodes in the linked list: ", num_nodes);
	for(int i = 0; i < num_nodes; i++)
	{
		scanf("%d", &node_val);
		push(&head, node_val);
	}

	printf("The original linked list is as follows:\n");
	printList(head);
	printf("\nIn this program, we swap the kth node from the beginning and end of the linked list\n");
	printf("\nk=1 list is derived from the original linked list; whereas, k=2 is derived from k=1 and so on\n");
	for(int k = 1; k <= num_nodes; k++)
	{
		swapkth(&head, k);
		printf("\nModified List for k = %d\n", k);
		printList(head);
	}
	return 0;
}
