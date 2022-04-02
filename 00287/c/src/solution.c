#include <stdlib.h>
#include <stdio.h>

void fprintarr(FILE *stream, int *arr, int size)
{
	fprintf(stream, "{");
	for (int i = 0; i < size - 1; i++)
	{
		fprintf(stream, "%d, ", arr[i]);
	}
	fprintf(stream, "%d}\n", arr[size - 1]);
}

int duplicate_old(int *arr, int size)
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

int duplicate(int *arr, int n)
{
	/*
	Note:
	Searching range of integeres [1, k], not elements in array.
	*/
	int p = 1, r = n;
	while (p < r) // p == r implies window minimized to encompass duplicate only.
	{
		int q = (p + r) / 2, acc = 0;
		#ifdef DEBUG
		fprintf(stdout, "searching [%d, %d] (q = %d)...\n", p, r, q);
		#endif
		for (int i = 0; i < n + 1; i++)
		{
			if (arr[i] <= q)
			{
				acc++;
			}
		}
		#ifdef DEBUG
		fprintf(stdout, "acc = %d\n", acc);
		#endif
		/*
		For each integer k in [1, n]:
		(number of elements in array <= k) == k for all k < duplicate
		So try to find smallest q == k that does not satisfy the above.
		*/
		if (q < acc)
		{
			/*
			Accumulator greater than q, so duplicate >= q.
			*/
			r = q;
		}
		else
		{
			p = q + 1;
		}
		#ifdef DEBUG
		fprintf(stdout, "Next interval: [%d, %d]\n", p, r);
		#endif
	}
	return p;
}

int main(int argc, char *argv[])
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 6}, size = sizeof(arr) / sizeof(arr[0]);
	fprintarr(stdout, arr, size);
	fprintf(stdout, "%d\n", duplicate(arr, size - 1));
	return EXIT_SUCCESS;
}
