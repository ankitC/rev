#include <stdio.h>
#include "linkedlist.h"

void main()
{
	struct node* head1 = BuildOneTwoThree();
	struct node* head2 = BuildOneTwoThree();

	struct node* current1 = head1;
	struct node* current2 = head2;
	struct node* next_current1 = current1->next;
	struct node* next_current2 = current2->next;

	while(next_current1 != NULL && next_current2 != NULL)
	{
		next_current1 = current1->next;
		next_current2 = current2->next;

		current1->next = current2;
		current2->next = next_current1;

		current1 = next_current1;
		current2 = next_current2;
	}

	current1 = head1;
	while(current1->next != NULL)
		current1 = current1->next;

	current1->next = next_current2;

	print_list(head1);
}
