#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ASCII_OFFSET 97

void print_arr(int *arr, int size)
{
	fprintf(stdout, "{");
	for (int i = 0; i < size - 1; i++)
	{
		fprintf(stdout, "%d, ", arr[i]);
	}
	fprintf(stdout, "%d}\n", arr[size - 1]);
}

bool in_interval(int n, int a, int b)
{
	return (a <= n) && (n <= b);
}

bool overlap(int start_a, int end_a, int start_b, int end_b)
{
	return
		(-1 < start_a) &&
		(-1 < start_b) &&
		(-1 < end_a) &&
		(-1 < end_b) &&
		(
			in_interval(start_a, start_b, end_b) ||
			in_interval(end_a, start_b, end_b) ||
			in_interval(start_b, start_a, end_a) ||
			in_interval(end_b, start_a, end_a)
		);
}

int *labels_partition(char *s, int *size_return)
{
	/* Get intervals for each letter. */
	int interval[26][2], length = strlen(s);
	for (int i = 0; i < 26; i++)
	{
		interval[i][0] = -1;
		interval[i][1] = -1;
	}
	for (char c = 'a'; c < 'z' + 1; c++)
	{
		for (int i = 0; i < length; i++)
		{
			if (s[i] == c)
			{
				interval[c - ASCII_OFFSET][0] = i;
				break;
			}
		}
		for (int i = length - 1; -1 < i; i--)
		{
			if (s[i] == c)
			{
				interval[c - ASCII_OFFSET][1] = i;
				break;
			}
		}
	}
	int *ret = NULL;
	*size_return = 0;
	int start = 0, stop = 0;
	for (int i = 0; s[i]; i++)
	{
		start = i;
		stop = interval[s[start] - ASCII_OFFSET][1];
		/* "Absorb" interval if it overlaps with any other letter intervals. */
		bool expanded = true;
		while (expanded)
		{
			expanded = false;
			for (char c = 'a'; c < 'z' + 1; c++)
			{
				int *interval_c = interval[c - ASCII_OFFSET];
				if
				(
					overlap(start, stop, interval_c[0], interval_c[1]) &&
					(stop < interval_c[1])
				)
				{
					stop = interval_c[1];
					/* If expanded, will need to run the check again to see if new interval overlaps any intervals not previously covered. */
					expanded = true;
				}
			}
		}
		(*size_return)++;
		ret = realloc(ret, (*size_return) * sizeof(int));
		ret[(*size_return) - 1] = stop - start + 1;
		i = stop;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	char *s = "qiejxqfnqceocmy";
	int size_return = 0;
	int *labels = NULL;
	// fprintf(stdout, "[%d, %d] and [%d, %d] %soverlap\n", 0, 8, 1, 9, overlap(0, 8, 1, 9) ? "" : "do not ");
	fprintf(stdout, "%s\n", s);
	labels = labels_partition(s, &size_return);
	print_arr(labels, size_return);
	free(labels);
	return EXIT_SUCCESS;
}
