#include "linkedlist.h"

int Count(struct node* head, int search_for);

void main()
{
	struct node* head = BuildOneTwoThree();
	print_list(head);
	int count = Count(head, 2);
	printf("Count is: %d\n", count);
}

int Count(struct  node* head, int search_for)
{
	int count = 0;
	if( head == NULL)
		return 0;
	struct node* current = head;
	while(current != NULL)
	{
		if(current->data == search_for)
			count++;
		current=current->next;
	}
	return count;
}
