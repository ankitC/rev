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
