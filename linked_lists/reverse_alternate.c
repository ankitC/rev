#include <stdio.h>
#include "linkedlist.h"

void main()
{
	struct node* head = BuildOneTwoThree();
	Push(&head, 10);
	Push(&head, 20);
	Push(&head, 30);

	struct node* current;
	struct node* even_head = NULL;
	struct node* even_next = NULL;
	print_list(head);
	current = head;

	while(current != NULL)
	{
		if(current->next != NULL)
		{
			even_next = current->next;
			current->next = current->next->next;
			current = even_next->next;
			even_next->next = even_head;
			even_head = even_next;
		}
		else
			current = NULL;
	}

	current = head;
	while(current->next != NULL)
		current = current->next;

	current->next = even_head;

	print_list(head);
}
