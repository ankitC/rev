#ifndef __SORT_H_
#define __SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void print_array(int a[], int length)
{
	int i = 0;
	for(i = 0; i<length; i++)
		printf("%d ",a[i]);
	printf("\n");
}

void generate_array(int a[], int length)
{
	int i = 0;
	srand ( time(NULL) );
	for(i=0;i<length; i++)
		a[i] = rand()%100;
}

#endif

