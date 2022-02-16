#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char *s, int i, int j)
{
	for (int k = 0; k < j - i / 2; k++)
	{
		if (s[i + k] != s[j - k])
		{
			return false;
		}
	}
	return true;
}
char *palindrome_longest(char *s)
{
	int len = 0, start;
	for (int i = 0; s[i] != '\0'; i++)
	{
		for (int j = i; s[j] != '\0'; j++)
		{
			if ((len < j - i + 1) && is_palindrome(s, i, j))
			{
				start = i;
				len = j - i + 1;
			}
		}
	}
	char *ret = NULL;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
	{
		perror("Failed to malloc \"ret\". Try downloading more RAM.\n");
		return NULL;
	}
	memcpy(ret, &s[start], len * sizeof(char));
	ret[len] = '\0';
	return ret;
}

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		char *pal = palindrome_longest(argv[i]);
		printf("Longest palindromic substring in \"%s\": %s\n", argv[i], pal);
		free(pal);
	}
	return EXIT_SUCCESS;
}
