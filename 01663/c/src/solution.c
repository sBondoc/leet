#include <stdlib.h>
#include <stdio.h>

#define BUFFER 100000
#define OFFSET_ASCII 97

char *string_smallest(int n, int k)
{
	static char ret[BUFFER] = {0};
	int i = n, leftover = k - n;
	for (ret[i--] = '\0'; 25 < leftover; i--)
	{
		ret[i] = 'z';
		leftover -= 25;
	}
	if (0 < leftover)
	{
		ret[i] = (char) leftover + OFFSET_ASCII;
	}
	for (i--; -1 < i; i--)
	{
		ret[i] = 'a';
	}
	return ret;
}

int main(int argc, char *argv[])
{
	fprintf(stdout, "%s\n", string_smallest(2, 18));
	return EXIT_SUCCESS;
}
