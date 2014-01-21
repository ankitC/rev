#include "sort.h"

#define MAXLENGTH 10

void bubble_sort(int a[], int length);
void selection_sort(int a[], int length);

void main()
{
	int a[MAXLENGTH] = {0};
	generate_array(a, MAXLENGTH);
	print_array(a,MAXLENGTH);
	printf("sorting...\n");
	selection_sort(a, MAXLENGTH);
	print_array(a,MAXLENGTH);
	return;
}

void selection_sort(int a[], int length)
{
	int i, j, temp;
	int min;

	for(i=0; i<length; i++)
	{
		min = i;
		for(j=i; j<length; j++)
		{
			if(a[j]<a[min])
				min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

void bubble_sort(int a[], int length)
{
	int i, j, temp;

	for(i=0; i<length; i++)
	{
		for(j=0; j<length - i - 1; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
