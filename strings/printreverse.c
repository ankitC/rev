#include <stdio.h>

void print_rev(char* s, int index)
{
	if(s == NULL)
		return;

	if(s[index] == '\0')
		return;

	print_rev(s, index + 1);

	printf("%c", s[index]);
	return;
}

void main()
{
	char* s = "ankit";
	print_rev(s, 0);
	printf("\n");
}
