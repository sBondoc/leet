#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_arr(int *arr, int size)
{
	fprintf(stdout, "{");
	for (int i = 0; i < size - 1; i++)
	{
		fprintf(stdout, "%d, ", arr[i]);
	}
	fprintf(stdout, "%d}\n", arr[size - 1]);
}

bool overlap(int start_a, int end_a, int start_b, int end_b)
{
	return
		(0 < start_a) &&
		(0 < start_b) &&
		(0 < end_a) &&
		(0 < end_b) &&
		((start_a <= end_b) || (start_b <= end_a));
}

int *labels_partition(char *s, int *size_return)
{
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
				interval[c - 97][0] = i;
				break;
			}
		}
		for (int i = length - 1; -1 < i; i--)
		{
			if (s[i] == c)
			{
				interval[c - 97][1] = i;
				break;
			}
		}
	}
	return malloc(sizeof(int));
}

int main(int argc, char *argv[])
{
	char *s = "babcbacadefegdehijhklij";
	int size_return = 0;
	int *labels = NULL;
	labels = labels_partition(s, &size_return);
	free(labels);
	return EXIT_SUCCESS;
}
