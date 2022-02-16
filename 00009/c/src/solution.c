#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int digit_n(int x, int n)
{
	for (int i = 0; i < n; i++)
	{
		x /= 10;
	}
	return x % 10;
}

int log_int(int x, int base)
{
	int ret = 0;
	for (int n = x; 0 < n; n /= base)
	{
		ret++;
	}
	return ret;
}

bool is_palindrome(int x)
{
	if (x < 0)
	{
		return false;
	}
	int digits = log_int(x, 10);
	for (int i = 0; i < digits; i++)
	{
		if (digit_n(x, i) != digit_n(x, digits - i - 1))
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	char **excess = NULL;
	int x = (argc < 2) ? 123454321 : strtol(argv[1], excess, 10);
	printf("%d is %sa palindrome.\n", x, is_palindrome(x) ? "" : "not ");
	return EXIT_SUCCESS;
}
