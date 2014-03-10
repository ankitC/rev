#include <stdio.h>

#define MAX 256
void main()
{
	short map[MAX] = {0};
	char* s = "bbbaaaacccccc";
	int max = 1;
	char max_char = s[0];
	int index = 0;

	while(s[index])
	{
		map[s[index]]++;
		if(map[s[index]] > max)
		{
			max = map[s[index]];
			max_char = s[index];
		}
		index++;
	}

	printf("max_char = %c count = %d\n", max_char, max);
}
