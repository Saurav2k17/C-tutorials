// Recursive implementation of printing the nth node from the end of a linked list

#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct Node
{
	int data;
	struct Node* next;
};

/* Function to get the nth node from the end of a linked list */
void printNthFromLast_recursive(struct Node *head, int n)
{
	static int i = 0;
	if(head == NULL)
		return;

	printNthFromLast_recursive(head->next, n);

	if(++i == n)
		printf("Node no. %d from the last is %d\n", n, head->data);
}

/* Function to insert a new node at the beginning of linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
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

	/* first with the empty list */
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

	printList(head);

	int value;
	printf("Which node value would you like to print from the end of the linked list: ");
	scanf("%d", &value);

	if(value > num_nodes)
	{
		printf("%d is greater than the no. of nodes in the list\n", value);
		return -1;
	}

	if(value <= 0)
	{
		printf("You entered an invalid number ! Program terminated\n");
		return -1;
	}
	printNthFromLast_recursive(head, value);
	return 0;
}
