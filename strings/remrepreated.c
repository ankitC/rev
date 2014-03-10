#include <stdio.h>
#include <string.h>

#define MAX 256

void main()
{
	char s[] = "ankit";
	char* sec = "ki";
	short map[MAX] = {0};
	int i;
	int read = 0, write = 0;

	for(i =0; i< strlen(sec); i++)
		map[sec[i]] = 1;

	/* <= to consider the null character */
	for(i = 0; i<= strlen(s); i++)
	{
		if(map[s[i]] == 1)
			continue;

		s[write] = s[i];
		write ++;
	}
	printf("%s \n", s);
}
