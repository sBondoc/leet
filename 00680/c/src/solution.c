#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool in_bounds(int n, int p, int r)
{
	return (p <= n) && (n <= r);
}

bool palindrome_valid_old(char *s)
{
	/*
	Intuition:
	Scan both ends of array, skip on one side and test to see if
	offset will fix it. If already an offset present then false.
	Cases that GMFU:
	Can skip either right or left (check next to solve).
	Checking next where overlap (decrement skipped index to solve).
	*/
	int len = strlen(s);
	int l = 0, r = len - 1, offset_l = 0, offset_r = 0;
	while (l <= r)
	{
		if (s[l + offset_l] != s[r - offset_r])
		{
			if (offset_l || offset_r)
			{
				return false;
			}
			if (s[l + 1] == s[r])
			{
				int i = l + 2, j = r - 1;
				if (j <= i)
				{
					j--;
				}
				if
				(
					(s[i] == s[j]) &&
					in_bounds(i, 0, len) &&
					in_bounds(j, 0, len)
				)
				{
					offset_l++;
					continue;
				}
			}
			if (s[l] == s[r - 1])
			{
				int i = l + 1, j = r - 2;
				if (j <= i)
				{
					i++;
				}
				if
				(
					(s[i] == s[j]) &&
					in_bounds(i, 0, len) &&
					in_bounds(j, 0, len)
				)
				{
					offset_r++;
					continue;
				}
			}
			return false;
		}
		l++;
		r--;
	}
	return true;
}

bool palindrome(char *s, int i, int j)
{
	while (i < j)
	{
		if (s[i] != s[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

bool palindrome_valid(char *s)
{
	int i = 0, j = strlen(s) - 1;
	while (i < j)
	{
		if (s[i] != s[j])
		{
			return palindrome(s, i, j - 1) || palindrome(s, i + 1, j);
		}
		i++;
		j--;
	}
	return true;
}

int main(int argc, char *argv[])
{
	char *s[] =
	{
		"aba",
		"abca",
		"abc",
		"adffdsa",
		"aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga",
		"cbbcc",
		"acxcybycxcxa",
	};
	int size = sizeof(s) / sizeof(s[0]);
	for (int i = 0; i < size; i++)
	{
		fprintf(stdout, "%s\n", s[i]);
		fprintf(stdout, "%s\n\n", (palindrome_valid(s[i])) ? "true" : "false");
	}
	return EXIT_SUCCESS;
}
