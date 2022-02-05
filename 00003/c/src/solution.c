#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE_BUFFER 95

void print_substring(char *s, int start, int stop)
{
	for (int i = start; i < stop + 1; i++)
	{
		printf("%c", s[i]);
	}
	printf("\n");
}

void print_str(char *s, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (s[i] != 0)
		{
			printf("%c", i + 32);
		}
	}
	printf("\n");
}

int length_longest_substring(char *s)
{
	int ret = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{	
		char present[SIZE_BUFFER] = {0};
		int n;
		for (n = i; (s[n] != '\0') && !present[s[n] - 32]; n++)
		{
			present[s[n] - 32] = 1;
		}
		if (ret < n - i)
		{
			ret = n - i;
		}
	}
	return ret;
}

int main(int argc, char **argv)
{
	char s[] = "pwwkew";
	printf("%s\n%d\n", s, length_longest_substring(s));
	return EXIT_SUCCESS;
}
