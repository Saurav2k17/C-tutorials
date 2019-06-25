// Binary search on a linked list

#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct Node
{
	int data;
	struct Node* next;
};

/* Function to find out middle element */
struct Node* middle(struct Node* first, struct Node* last)
{
	if(first == NULL)
		return NULL;

	struct Node* slow = first;
	struct Node* fast = first->next;

	while(fast != last)
	{
		fast = fast->next;
		if(fast != last)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	return slow;
}

/* Function to implement the Binary Search on linked list */
struct Node* binarySearch(struct Node *head, int value)
{
	struct Node* first = head;
	struct Node* last = NULL;

	do
	{
		// Find middle
		struct Node* mid = middle(first, last);

		// If middle is empty
		if(mid == NULL)
			return NULL;

		// If value is present in the middle
		if(mid->data == value)
			return mid;

		// If value is more than mid
		else if(mid->data < value)
			first = mid->next;

		// If value is less than mid
		else
			last = mid;

	} while(last == NULL ||
			last != first);

	// value not found
	return NULL;
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

	/* first with the empty list */
	struct Node* head = NULL;

	push(&head, 13);
	push(&head, 10);
	push(&head, 9);
	push(&head, 7);
	push(&head, 5);
	push(&head, 3);
	push(&head, 1);

	printList(head);

	int value;
	printf("Find a value: ");
	scanf("%d", &value);
	if (binarySearch(head, value) == NULL)
		printf("%d is not present\n", value);
	else
		printf("%d is present\n", value);
	return 0;
}
