#include <stdio.h>
#include "linkedlist.h"

void split_helper(struct node* current, struct node** evenref, struct node** oddref)
{
	if(current == NULL)
		return;

	split_helper(current->next, evenref, oddref);
	if(current->data %2 == 0)
	{
		current->next = *evenref;
		*evenref = current;
		return;
	}
	current->next = *oddref;
	*oddref = current;
	return;
}

void split_even_odd(struct node** headref)
{
	struct node* even = NULL;
	struct node* odd = NULL;
	split_helper(*headref, &even, &odd);

	struct node* current = even;
	while(current != NULL && current->next != NULL)
		current = current->next;

	current->next = odd;
	*headref = even;
	return;
}


void main()
{
	struct node* head = BuildOneTwoThree();
	Push(&head, 12);
	Push(&head, 11);
	Push(&head, 13);
	Push(&head, 14);
	Push(&head, 15);
	Push(&head, 16);
	print_list(head);
	split_even_odd(&head);
	print_list(head);
}


