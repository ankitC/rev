#include "linkedlist.h"

int Count(struct node* head, int search_for);

void main()
{
	struct node* head = BuildOneTwoThree();
	print_list(head);
//	int count = Count(head, 2);
	int count = get_nth(head, 0);
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

int get_nth(struct node* head, int position)
{
	int i = 0;
	int data;
	struct node* current = head;
	if(position > list_length(head) - 1)
	{
		printf("Invalid Position.\n");
		return 0;
	}

	for(i = 0; i< position; i++)
	{
		current = current->next;
	}
	data = current->data;
	return data;
}
