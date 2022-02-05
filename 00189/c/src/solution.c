#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4

void print_arr(int *arr, int size)
{
	printf("{");
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\b\b}\n");
}

void rotate_mem(int *arr, int size, int k)
{
	int r[k];
	memcpy(&r, &arr[size - k], k * sizeof(int));
	memcpy(&arr[size - k - 1], arr, (size - k + 1) * sizeof(int));
	memcpy(arr, &r, k * sizeof(int));
}

void rotate(int *arr, int size, int k)
{
	k = k % size;
	if (k != 0)
	{
		#ifdef DEBUG
		print_arr(arr, size);
		#endif
		int l[size - k], r[k];
		for (int i = 0; i < size - k; i++)
		{
			l[i] = arr[i];
		}
		#ifdef DEBUG
		print_arr(l, size - k);
		#endif
		for (int i = 0; i < k; i++)
		{
			r[i] = arr[size - k + i];
		}
		#ifdef DEBUG
		print_arr(r, k);
		#endif
		int j = 0;
		for (int i = 0; i < k; i++)
		{
			arr[j] = r[i];
			j++;
		}
		#ifdef DEBUG
		print_arr(arr, size);
		#endif
		for (int i = 0; i < size - k; i++)
		{
			arr[j] = l[i];
			j++;
		}
		#ifdef DEBUG
		print_arr(arr, size);
		#endif
	}
}

int main(int argc, char **argv)
{
	int arr[SIZE] = {-1, -100, 3, 99};
	rotate(arr, SIZE, 2);
	return EXIT_SUCCESS;
}
