#include <stdio.h>
#include <stdlib.h>
void fprintarr(FILE *stream, int *arr, int size)
{
	fprintf(stream, "{");
	for (int i = 0; i < size - 1; i++)
	{
		fprintf(stream, "%d, ", arr[i]);
	}
	fprintf(stream, "%d}", arr[size - 1]);
}
void remove_duplicates(int *arr, int size)
{
	for (int i = size - 1; 0 < i; i--)
	{
		if (arr[i] == arr[i - 1])
		{
			for (int j = i; j < size; j++)
			{
				arr[j - 1] = arr[j];
			}
		}
	}
}
int main(void)
{
	int arr[] = {0, 0, 1, 2, 3, 4, 5, 5, 5, 5, 6, 6, 7, 8, 9, 9, 10, 10, 10};
	int size = sizeof(arr) / sizeof(arr[0]);
	fprintarr(stdout, arr, size);
	fprintf(stdout, "\n");
	remove_duplicates(arr, size);
	fprintarr(stdout, arr, size);
	fprintf(stdout, "\n");
	return EXIT_SUCCESS;
}
