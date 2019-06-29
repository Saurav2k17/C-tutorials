// Print the nth node from the end of a linked list

#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct Node
{
	int data;
	struct Node* next;
};

/* Function to get the nth node from the end of a linked list */
void printNthFromLast(struct Node *head, int n)
{
	if(n <= 0)
	{
		printf("You entered an invalid number ! Program terminated\n");
		return;
	}

	struct Node *main_ptr = head;
	struct Node *ref_ptr = head;

	int count = 0;

	if(head != NULL) // with our main function, the head can never be NULL
	{
		while(count < n)
		{
			if(ref_ptr == NULL)
			{
				printf("%d is greater than the no. of nodes in the list\n", n);
				return;
			}
			ref_ptr = ref_ptr->next;
			count++;
		}

		while(ref_ptr != NULL)
		{
			main_ptr = main_ptr->next;
			ref_ptr  = ref_ptr->next;
		}
		printf("Node no. %d from the last is %d\n", n, main_ptr->data);
	}
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
	printNthFromLast(head, value);
	return 0;
}
