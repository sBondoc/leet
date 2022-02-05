#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, int size)
{
	printf("{");
	for (int i = 0; i < size - 1; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("%d}\n", arr[size - 1]);
}

int *sum_two(int *nums, int size_nums, int target, int *size_return)
{
	*size_return = 2;
	int *ret = malloc(2 * sizeof(int));
	for (int i = 0; i < size_nums; i++)
	{
		for (int j = i + 1; j < size_nums; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				ret[0] = i;
				ret[1] = j;
				return ret;
			}
		}
	}
	return NULL;
}

int main(int argc, char **argv)
{
	int nums[] = {2, 7, 11, 15};
	int size_return = 2;
	int *arr = sum_two(nums, 4, 9, &size_return);
	print_arr(arr, size_return);
	free(arr);
	return EXIT_SUCCESS;
}
