#include <stdlib.h>
#include <stdio.h>

void print_arr(int *arr, int size)
{
	if (size < 1)
	{
		printf("{}\n");
		return;
	}
	printf("{");
	for (int i = 0; i < size - 1; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("%d}\n", arr[size - 1]);
}

int **subsets(int *nums, int size, int *size_return, int **sizes_columns)
{
	(*size_return) = 1 << size;
	int **ret = NULL;
	ret = malloc((*size_return) * sizeof(int *));
	if (ret == NULL)
	{
		perror("Failed to malloc \"size_return\". Try downloading more RAM.\n");
		return NULL;
	}
	(*sizes_columns) = NULL;
	(*sizes_columns) = malloc((*size_return) * sizeof(int));
	if ((*sizes_columns) == NULL)
	{
		perror("Failed to malloc \"sizes_columns\". Try downloading more RAM.\n");
		return NULL;
	}
	/*
		Rationale: View every bit as a selection in the array. Say we want every
		possible combination from a set of 5. Map each item to a bit. Each possible
		combination is covered by a 5-bit number, so iterating through every 5-bit
		number yields every combination.
	*/
	for (unsigned int subset = 0; subset < (unsigned int) *size_return; subset++)
	{
		int size_subset = 0;
		for (int i = 0; i < size; i++)
		{
			if ((subset >> i) & 1)
			{
				size_subset++;
			}
		}
		int *subset_new = NULL;
		subset_new = malloc(size_subset * sizeof(int));
		if (subset_new == NULL)
		{
			perror("Failed to malloc \"subset_new\". Try downloading more RAM.\n");
			return NULL;
		}
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if ((subset >> i) & 1)
			{
				subset_new[j] = nums[i];
				j++;
			}
		}
		(*sizes_columns)[subset] = size_subset;
		ret[subset] = subset_new;
	}
	return ret;
}

int main(int argv, char *argc[])
{
	int nums[] = {1, 2, 3, 4, 5};
	int size_return = 0;
	int *sizes_columns = NULL;
	int **sets = subsets(nums, sizeof(nums) / sizeof(nums[0]), &size_return, &sizes_columns);
	for (int i = 0; i < size_return; i++)
	{
		print_arr(sets[i], sizes_columns[i]);
		free(sets[i]);
	}
	free(sets);
	free(sizes_columns);
	return EXIT_SUCCESS;
}
