#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool two_power(int n)
{
	return (1 <= n) && !(n & (n - 1));
}

int main(int argc, char **argv)
{
	for (int i = 0; i < 20; i++)
	{
		printf("%02d is %sa power of 2.\n", i, two_power(i) ? "" : "not ");
	}
	return EXIT_SUCCESS;
}
