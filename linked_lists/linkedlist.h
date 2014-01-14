#ifndef _LH_H_
#define _LH_H_
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int data;
	struct node* next;
}node_t;

typedef struct linked_list
{
	node_t* head;
}linked_list_t;

void Push(struct node** headRef, int newData)
{
	struct node* newNode =
		(struct node*) malloc(sizeof(struct node)); // allocate node
	newNode->data = newData; // put in the data
	newNode->next = (*headRef); // link the old list off the new node
	(*headRef) = newNode; // move the head to point to the new node
}

struct node* BuildOneTwoThree()
{
	struct node* head = NULL; // Start with the empty list
	Push(&head, 3); // Use Push() to add all the data
	Push(&head, 2);
	Push(&head, 1);
	return(head);
}

int list_length(struct node* head)
{
	int count = 0;
	struct node* current = head;

	while(current!=NULL)

void print_list(struct node* head)
{
	if( head == NULL )
		printf("List is empty!\n");
	else
	{
		struct node* current = head;
		while(current!=NULL)
		{
			printf("%d\t", current->data);
			current = current->next;
		}
		printf("\n");
	}
}

#endif
