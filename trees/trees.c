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

void double_tree(struct node* node)
{
	if(node==NULL)
		return;
	double_tree(node->left);
	double_tree(node->right);
	struct node* new_node1 = new_node(node->data);
	new_node1->left = node->left;
	node->left = new_node1;
}

int same_tree(struct node* a, struct node* b)
{
	int right_value = 0, left_value = 0;

	if(a->left!=NULL && b->left!=NULL)
		left_value = same_tree(a->left, b->left);
	else if(a->left==NULL && b->left==NULL)
		left_value = 1;

	if(a->right!=NULL && b->right!=NULL)
		right_value = same_tree(a->right, b->right);
	else if(a->right==NULL && b->right==NULL)
		right_value = 1;

	if(a->data == b->data)
		return (1 && left_value && right_value);
	else
		return 0;
}

void main()
{
	int n = 0;
	struct node* root = build123();
	root = insert(root, 5);
	root = insert(root, 9);
	root = insert(root, 4);
	root = insert(root , 6);
	root = insert(root , 10);
	print_inorder(root);
	printf("\n");
//	print_inorder(root);

	struct node* root1 = build123();
	root1 = insert(root1, 5);
	root1 = insert(root1 , 10);
	root1 = insert(root1, 9);
	root1 = insert(root1, 4);
	root1 = insert(root1 , 6);
	print_inorder(root1);
	printf("\n");
	//print_inorder(root1);

	n=same_tree(root, root1);
	printf("Same:%d\n", n);
	return;
}
