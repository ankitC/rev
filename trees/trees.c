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

int has_path_sum(struct node* node, int sum)
{
	int chksum = sum;
	int retval = 0;
	if(node->data == sum && node->right == NULL && node->left == NULL)
		return 1;
	chksum = sum - node->data;
	if(chksum > 0 && node->left!=NULL && !retval)
		retval = has_path_sum(node->left, chksum);

	if(chksum > 0 && node->right!=NULL && !retval)
		retval = has_path_sum(node->right, chksum);
	return retval;
}

void mirror(struct node* node)
{
	if(node == NULL)
		return;
	struct node* right_node = NULL;
	struct node* left_node = NULL;

	mirror(node->left);
	mirror(node->right);

	struct node* temp = node->left;
	node->left = node->right;
	node->right = temp;

	return;
}

void print_paths_recur(struct node* node, int a[], int position)
{
	int i = 0;
	if(node->left == NULL && node->right == NULL)
	{
		a[position] = node->data;
		for(i=0; i<=position; i++)
			printf("%d\t",a[i]);
		printf("\n");
		return;
	}
	a[position] = node->data;
	position++;
	if(node->left!=NULL)
		print_paths_recur(node->left, a, position);
	if(node->right!=NULL)
		print_paths_recur(node->right,a, position);
}

void print_paths(struct node* node)
{
	int size = max_depth(node);
	int a[size];
	int position = 0;
	//a[position] = node->data;
	//position++;
	print_paths_recur(node, a, position);
}


void main()
{
	struct node* root = build123();
	int maxdepth = max_depth(root);
	root = insert(root, 5);
	root = insert(root, 9);
	root = insert(root, 4);
	//root = insert(root, -2);
	root = insert(root , 6);
	root = insert(root , 10);
	print_inorder(root);
	printf("\n");
	print_paths(root);

	return;
}
