// Find the middle node of the linked list

#include <stdio.h> 
#include <stdlib.h>

// A Linked List Node
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 
 
/* Function to get the middle of the linked list */
void printMiddle(struct Node *head) 
{ 
	struct Node *slow_ptr = head; 
	struct Node *fast_ptr = head; 

	if (head != NULL) 
	{ 
		while(fast_ptr != NULL && fast_ptr->next != NULL) 
		{ 
			fast_ptr = fast_ptr->next->next; 
			slow_ptr = slow_ptr->next; 
		} 
		printf("The middle element is [%d]\n\n", slow_ptr->data); 
	} 
	else
		printf("The linked list is empty");
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
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

/* Driver program to test above functions */
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	for (int i = 10; i > 0; i--)
	{
		push(&head, i);
		printList(head);
		printMiddle(head);
	}

	return 0;
}
