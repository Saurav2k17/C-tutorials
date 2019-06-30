// Program to reverse the node values in a linked list
// e.g., Input: 128->32->43 Output: 821->23->34

#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct Node
{
	int data;
	struct Node* next;
};

struct Node* next_node; // updates the next node

// reverse() receives individual data item
// from reverseIndividualData() and returns
// the reversed number to the calling function
int reverse(int number)
{
	int new_num = 0, rem;

	while(number != 0)
	{
		rem = number % 10;
		new_num = new_num * 10 + rem;
		number = number / 10;
	}
	return new_num;
}

void reverseIndividualData(struct Node* node)
{
	while(node != NULL)
	{
		node->data = reverse(node->data);
		node = node->next;
	}
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

	printf("The linked list before the node values are reversed:\n");
	printList(head);
	reverseIndividualData(head);
	printf("The linked list after the node values are reversed:\n");
	printList(head);
	return 0;
}
