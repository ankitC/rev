#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* new_node(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left =NULL;
	node->right = NULL;
}

struct node* insert(struct node* node, int data)
{

	if(node == NULL)
		return new_node(data);

	if(node->data > data)
	{
		node->left =  insert(node->left, data);
		return node;
	}
	else
	{
		node->right = insert(node->right, data);
		return node;
	}
}

void print_inorder(struct node* node)
{
	if(node == NULL)
		return;
	print_inorder(node->left);
	printf("%d\t",node->data);
	print_inorder(node->right);
}

void print_postorder(struct node* node)
{
	if(node == NULL)
		return;
	print_inorder(node->left);
	print_inorder(node->right);
	printf("%d\t",node->data);
}


struct node* build123()
{
	struct node* root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	print_inorder(root);
	printf("\n");
	return root;
}
