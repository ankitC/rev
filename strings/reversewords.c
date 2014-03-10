#include <stdio.h>
#include <string.h>


void reverse(char* s, int start, int end);

void main()
{
	char s[] = "ankit chheda";
	int start = 0;
	int end = strlen(s) - 1;
	printf("%d\n", end);
	reverse(s, start, end);
	printf("%s\n",s);

	start = 0;
	end = 0;
	while(s[end] != '\0')
	{
		while(!isspace(s[end]) && s[end] != '\0')
			end++;

		printf("end = %d\n", end);
		reverse(s,start, end-1);
		start = end + 1;
		end++;
	}
	printf("%s\n", s);
}

void reverse(char* s, int start, int end)
{
	int left = start;
	int right = end;
	char temp;
	while(left < right)
	{
//		printf("%s %c %c\n", s, s[left], s[right]);
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;
		right--;
	}
}
