#include <stdlib.h>
#include <stdio.h>

int duplicate(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((i != j) && (arr[i] == arr[j]))
			{
				return arr[i];
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int arr[] = {3, 1, 3, 4, 2}, size = sizeof(arr) / sizeof(arr[0]);
	fprintf(stdout, "%d\n", duplicate(arr, size));
	return EXIT_SUCCESS;
}
