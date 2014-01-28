#include "trees.h"

int size1(struct node* node, int* n)
{
	if(node->left!=NULL)
		size(node->left, n);
	if(node->right!=NULL)
		size(node->right, n);
	(*n)++;
}

int size(struct node* node)
{
	if(node == NULL)
		return 0;
	int n = 1 + size(node->left) + size(node->right);
	return n;
}


int max_depth(struct node* node)
{
	if(node == NULL)
		return 0;
	int left_depth = 1+max_depth(node->left);
	int right_depth = 1+max_depth(node->right);
	if(right_depth >= left_depth)
		return right_depth;
	else
		return left_depth;
}


int min_value(struct node* node)
{
	int min_val;
	int left_value, right_value;

	min_val = node->data;

	if(node->left != NULL)
	{
		left_value = min_value(node->left);
		if(min_val > left_value)
			min_val = left_value;
	}

	if(node->right!=NULL)
	{
		right_value = min_value(node->right);
		if(min_val > right_value)
			min_val = right_value;
	}
	return min_val;
}

int max_value(struct node* node)
{
	int max_val;
	int left_value, right_value;

	max_val = node->data;

	if(node->left != NULL)
	{
		left_value = max_value(node->left);
		if(max_val < left_value)
			max_val = left_value;
	}

	if(node->right!=NULL)
	{
		right_value = max_value(node->right);
		if(max_val < right_value)
			max_val = right_value;
	}
	return max_val;
}


void main()
{
	struct node* root = build123();
	root = insert(root, 5);
	root = insert(root, 9);
	root = insert(root, 4);
	//root = insert(root, -2);
	root = insert(root , 10);
	print_inorder(root);
	printf("\n");

	//print_postorder(root);
	int n = max_value(root);
	printf("%d\n", n);

	return;
}
