#include "linkedlist.h"
#include <assert.h>

int Count(struct node* head, int search_for);
int get_nth(struct node* head, int position);
void delete_list(struct node** head);
int pop(struct node** headRef);
void insert_nth(struct node** headRef, int pos, int element);
void sorted_insert(struct node** headRef, struct node* new_node);
void insert_sort(struct node** headRef);
void append(struct node** a, struct node** b);
void front_back_split(struct node* source, struct node** frontRef, struct node** backRef);
void remove_duplicates(struct node* head);
void move_node(struct node** dest, struct node** source);
void alternating_split(struct node* source, struct node** aRef, struct node** bRef);
struct node* shuffle_merge(struct node* a, struct node* b);
struct node* sorted_merge(struct node* a, struct node* b);
void merge_sort(struct node** headRef);

void main()
{
	struct node* head = BuildOneTwoThree();
	print_list(head);
//	int count = Count(head, 2);
//	int count = get_nth(head, 0);
//	printf("Count is: %d\n", count);
//	delete_list(&head);
//	print_list(head);
//	int i = 0;
//	int length = list_length(head);
/*	for(i = 0; i<length; i++)
	{
		int c = pop(&head);
		printf("%d\t", c);
	}
	printf("\n");
*/
//	insert_nth(&head,0,10);
//	print_list(head);
#ifdef SORTED_INSERT
	struct node* new_node1 = (struct node*) malloc(sizeof(struct node));
	new_node1->data = 13;
	sorted_insert(&head, new_node1);
	print_list(head);
	struct node* new_node2 = (struct node*) malloc(sizeof(struct node));
	new_node2->data = 0;
	sorted_insert(&head, new_node2);
	print_list(head);
	struct node* new_node3 = (struct node*) malloc(sizeof(struct node));
	new_node3->data = 8;
	sorted_insert(&head, new_node3);
	print_list(head);
	struct node* new_node4 = (struct node*) malloc(sizeof(struct node));
	new_node4->data = 4;
	sorted_insert(&head, new_node4);
	print_list(head);
	struct node* new_node5 = (struct node*) malloc(sizeof(struct node));
	new_node5->data = 30;
	sorted_insert(&head, new_node5);
	print_list(head);
#endif

#ifdef INSERT_SORT
	insert_nth(&head,0,10);
	insert_nth(&head,1,20);
	insert_nth(&head,3,14);
	insert_nth(&head,4,78);
	insert_nth(&head,1,32);
	insert_nth(&head,3,42);
	print_list(head);
	insert_sort(&head);
	print_list(head);
#endif

#ifdef APPEND	
	struct node* head1 = BuildOneTwoThree();
	insert_nth(&head1,0,10);
	print_list(head1);
	append(&head,&head1);
	print_list(head);
	print_list(head1);
#endif

#ifdef SPLIT_FRONT_BACK
	struct node* new_node5 = (struct node*) malloc(sizeof(struct node));
	new_node5->data = 30;
	sorted_insert(&head, new_node5);
	struct node* new_node6 = (struct node*) malloc(sizeof(struct node));
	new_node6->data = 10;
	sorted_insert(&head, new_node6);

	struct node* head1 = NULL;
	struct node* head2=NULL;
	front_back_split(head, &head1, &head2);
	print_list(head1);
	print_list(head2);
#endif
#ifdef REMOVE_DUPLICATES
	struct node* new_node5 = (struct node*) malloc(sizeof(struct node));
	new_node5->data = 2;
	sorted_insert(&head, new_node5);
	struct node* new_node6 = (struct node*) malloc(sizeof(struct node));
	new_node6->data = 1;
	sorted_insert(&head, new_node6);
	print_list(head1);
	remove_duplicates(head1);
	print_list(head1);
#endif

#ifdef MOV_NODE
	struct node* a = BuildOneTwoThree();
	struct node* b = BuildOneTwoThree();
	print_list(a);
	print_list(b);

	move_node(&a,&b);
	print_list(a);
	print_list(b);
#endif

#ifdef ALTERNATING_SPLIT
	struct node* a = NULL;
	struct node* b = NULL;
	alternating_split(head, &a, &b);
	print_list(a);
	print_list(b);
#endif

#ifdef SHUFFLE_MERGE
	struct node* a = BuildOneTwoThree();
	struct node* b = BuildOneTwoThree();
	print_list(a);
	print_list(b);
	struct node* c = shuffle_merge(a,b);
	print_list(c);
#endif

#ifdef SORTED_MERGE
	struct node* a = BuildOneTwoThree();
	struct node* b = BuildOneTwoThree();
	struct node* new_node1 = (struct node*) malloc(sizeof(struct node));
	new_node1->data = 13;
	sorted_insert(&a, new_node1);
	struct node* new_node2 = (struct node*) malloc(sizeof(struct node));
	new_node2->data = 0;
	sorted_insert(&b, new_node2);
	struct node* new_node3 = (struct node*) malloc(sizeof(struct node));
	new_node3->data = 8;
	sorted_insert(&a, new_node3);
	struct node* new_node4 = (struct node*) malloc(sizeof(struct node));
	new_node4->data = 4;
	sorted_insert(&a, new_node4);
	struct node* new_node5 = (struct node*) malloc(sizeof(struct node));
	new_node5->data = 30;
	sorted_insert(&b, new_node5);
	print_list(a);
	print_list(b);
	struct node* c = sorted_merge(a,b);
	print_list(c);
#endif
	insert_nth(&head,0,10);
	insert_nth(&head,1,20);
	insert_nth(&head,3,14);
	insert_nth(&head,4,78);
	insert_nth(&head,1,32);
	insert_nth(&head,3,42);
	print_list(head);
	merge_sort(&head);
//	print_list(head);


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

void delete_list(struct node** head)
{
	struct node* current = *head;
	struct node* to_free;

	while(current!=NULL)
	{
		to_free = current;
		current = current->next;
		free(to_free);
	}
	*head = NULL;
	return;
}

int pop(struct node** headRef)
{
	struct node* head = *headRef;
	if(head == NULL)
		return 0;
	int retval = head->data;
	*headRef = (*headRef)->next;
	free(head);
	return retval;
}

void insert_nth(struct node** headRef, int pos, int element)
{
	struct node* head = *headRef;
	struct node* current = head;
	int i = 0;
	if(pos > (list_length(head) + 1))
	{
		printf("Trying to insert at invalid position!\n");
		return;
	}

	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = element;
	if(pos == 0)
	{
		new_node->next = head;
		*headRef = new_node;
		return;
	}

	for(i=0; i<pos-1; i++)
		current = current->next;

	new_node->next = current->next;
	current->next = new_node;
}

void sorted_insert(struct node** headRef, struct node* new_node)
{
	struct node* current = *headRef;
	struct node* previous = NULL;

	/* Empty List */
	if(current == NULL)
	{
		new_node->next == NULL;
		*headRef = new_node;
		return;
	}

	/* Insert at the head */
	if(new_node->data <= current->data)
	{
		new_node->next = current;
		*headRef = new_node;
		return;
	}

	while((current->data <=new_node->data)&&current->next!=NULL)
	{
		previous = current;
		current = current->next;
	}

	/* Insert at the tail */
	if(current->next == NULL && (current->data < new_node->data))
	{
		current->next = new_node;
		new_node->next = NULL;
		return;
	}

	/* Insert in between */
	previous->next = new_node;
	new_node->next = current;
	return;
}


void insert_sort(struct node** headRef)
{
	struct node* head = *headRef;
	struct node* new_head = NULL;
	struct node* next_head = NULL;
	while(head != NULL)
	{
		next_head = head->next;
		head->next = NULL;
		sorted_insert(&new_head, head);
		head = next_head;
	}

	*headRef = new_head;
}

void append(struct node** a, struct node** b)
{
	if(*b == NULL)
		return;
	if(*a == NULL)
	{
		*a = *b;
		*b = NULL;
		return;
	}

	struct node* current = *a;
	while(current->next!=NULL)
		current = current->next;
	current->next = *b;
		*b = NULL;
}

void front_back_split(struct node* source, struct node** frontRef, struct node** backRef)
{
	if(source == NULL)
	{
		*frontRef = NULL;
		*backRef = NULL;
		return;
	}
	*frontRef = source;
	int length = list_length(source);
	int i = 0;
	for(i = 0; i<(length-length/2)-1; i++)
		source = source->next;
	*backRef = source->next;
	source->next = NULL;
}

void remove_duplicates(struct node* head)
{
	if(head == NULL||head->next == NULL)
		return;
	struct node* current = head;
	struct node* next_node = head->next;
	struct node* to_free = NULL;
	do
	{
		if(current->data == next_node->data)
		{
			to_free = next_node;
			next_node = next_node->next;
			current->next = next_node;
			free(to_free);
			continue;
		}
		current=current->next;
		next_node = next_node->next;
	}while(next_node!=NULL);
}

void move_node(struct node** dest, struct node** src)
{
	if(*src == NULL)
		return;
	struct node* temp = *src;
	*src = (*src)->next;

	temp->next = *dest;
	*dest = temp;
}


void alternating_split(struct node* source, struct node** aRef, struct node** bRef)
{
	*aRef = NULL;
	*bRef = NULL;
	while(source!=NULL)
	{
		move_node(aRef, &source);
		if(source!=NULL)
			move_node(bRef, &source);
	}
}

struct node* shuffle_merge(struct node* a, struct node* b)
{
	struct node* returned;
	if(a == NULL && b == NULL)
		return NULL;
	else if(a == NULL && b!=NULL)
	{
		returned = shuffle_merge(NULL, b->next);
		b->next = returned;
		return b;
	}
	else if(a!=NULL && b==NULL)
	{
		returned = shuffle_merge(a->next, NULL);
		a->next = returned;
		return a;
	}
	else if(a!=NULL && b!=NULL) //I knw its a redundant statement!!
	{
		returned = shuffle_merge(a->next, b->next);
		b->next = returned;
		a->next = b;
		return a;
	}
}

struct node* sorted_merge(struct node* a, struct node* b)
{
	struct node* returned = NULL;
	if(a==NULL && b==NULL)
		return NULL;
	else if(a!=NULL && b==NULL)
	{
		returned = sorted_merge(a->next, NULL);
		move_node(&returned, &a);
	}
	else if(a==NULL && b!=NULL)
	{
		returned = sorted_merge(NULL, b->next);
		move_node(&returned, &b);
	}
	else if(a!=NULL && b!=NULL)
	{
		if(b->data <= a->data)
		{
			returned = sorted_merge(a, b->next);
			b->next == NULL;
			move_node(&returned,&b);
			//a->next == NULL;
			//move_node(&returned,&a);
		}
		else
		{
			returned = sorted_merge(a->next, b);
			a->next == NULL;
			move_node(&returned,&a);
			//b->next == NULL;
			//move_node(&returned,&b);
		}
	}
	return returned;
}

void merge_sort(struct node** headRef)
{
	struct node* part1 = NULL;
	struct node* part2 = NULL;

	print_list(*headRef);
	if((*headRef)->next == NULL)
		return;
	front_back_split(*headRef,&part1,&part2);
	if(part1!=NULL)
		merge_sort(&part1);
	print_list(part1);
	if(part2!=NULL)
		merge_sort(&part2);
	print_list(part2);
	*headRef = sorted_merge(part1,part2);
	print_list(*headRef);
	return;
}
