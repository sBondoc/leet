#include <stdlib.h>
#include <stdio.h>
long long zero_filled_subarrays(int *arr, int size)
{
	long long subarrays = 0;
	for (int i = 0; i < size; i++)
	{
		long long zero_count = 0;
		for (; (i < size) && (arr[i] == 0); i++)
		{
			zero_count++;
		}
		subarrays += ((zero_count) * (zero_count + 1)) / 2;
	}
	return subarrays;
}
int main(void)
{
	int arr[] = {1, 3, 0, 0, 2, 0, 0, 4};
	int size = sizeof(arr) / sizeof(arr[0]);
	fprintf(stdout, "Zero-filled subarrays: %lld\n", zero_filled_subarrays(arr, size));
	return EXIT_SUCCESS;
}
