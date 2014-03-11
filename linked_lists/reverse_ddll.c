#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

void reverse(struct node** headref)
{
	if(headref == NULL || *headref == NULL)
		return;

	struct node* current = *headref;
	struct node* temp = NULL;
	struct node* prev = NULL;

	while(current != NULL)
	{
		prev = current;
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		current = current->prev;
	}

	*headref = prev;
}

void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
		(struct node*) malloc(sizeof(struct node));

	/* put in the data  */
	new_node->data  = new_data;

	/* since we are adding at the begining,
	 *       prev is always NULL */
	new_node->prev = NULL;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* change prev of head node to new node */
	if((*head_ref) !=  NULL)
		(*head_ref)->prev = new_node ;

	/* move the head to point to the new node */
	(*head_ref)    = new_node;
}

/* Function to print nodes in a given doubly linked list
 *    This function is same as printList() of singly linked lsit */
void printList(struct node *node)
{
	while(node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct node* head = NULL;

	/* Let us create a sorted linked list to test the functions
	 *    Created linked list will be 10->8->4->2 */
	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);

	printf("\n Original Linked list ");
	printList(head);

	/* Reverse doubly linked list */
	reverse(&head);

	printf("\n Reversed Linked list ");
	printList(head);

	getchar();
}
