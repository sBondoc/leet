#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
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

bool equal(int *arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		if (arr[i] != arr[0])
		{
			return false;
		}
	}
	return true;
}

void flip(int *arr1, int *arr2, int i)
{
	int temp = arr1[i];
	arr1[i] = arr2[i];
	arr2[i] = temp;
}

int rotations_min_old(int *tops, int size_tops, int *bottoms, int size_bottoms)
{
	int ret = INT_MAX;
	unsigned int combinations = 1 << size_tops;
	fprintf(stdout, "combinations: %u\n", combinations);
	for (unsigned int i = 0; i < combinations; i++)
	{
		int flips = 0, top[size_tops], bottom[size_bottoms];
		memcpy(top, tops, size_tops * sizeof(int));
		memcpy(bottom, bottoms, size_bottoms * sizeof(int));
		for (int j = 0; j < size_tops; j++)
		{
			if (i >> j & 1)
			{
				flip(top, bottom, j);
				flips++;
			}
		}
		if ((equal(top, size_tops) || equal(bottom, size_bottoms)) && (flips < ret))
		{
			ret = flips;
		}
	}
	if (ret < INT_MAX)
	{
		return ret;
	}
	return -1;
}

int rotations_min(int *tops, int size_tops, int *bottoms, int size_bottoms)
{
	int ret = INT_MAX;
	for (int i = 1; i < 7; i++)
	{
		bool eligible = true;
		/* Check tops */
		int flips = 0, top[size_tops], bottom[size_bottoms];
		memcpy(top, tops, size_tops * sizeof(int));
		memcpy(bottom, bottoms, size_bottoms * sizeof(int));
		for (int j = 0; j < size_tops; j++)
		{
			if (top[j] != i)
			{
				flip(top, bottom, j);
				if ((top[j] == i) && (flips < ret))
				{
					flips++;
				}
				else
				{
					eligible = false;
					break;
				}
			}
		}
		if (eligible && (flips < ret))
		{
			ret = flips;
		}
		/* Check bottoms */
		flips = 0, eligible = true;
		memcpy(top, tops, size_tops * sizeof(int));
		memcpy(bottom, bottoms, size_bottoms * sizeof(int));
		for (int j = 0; j < size_bottoms; j++)
		{
			if (bottom[j] != i)
			{
				flip(top, bottom, j);
				if ((bottom[j] == i) && (flips < ret))
				{
					flips++;
				}
				else
				{
					eligible = false;
					break;
				}
			}
		}
		if (eligible && (flips < ret))
		{
			ret = flips;
		}

	}
	if (ret < INT_MAX)
	{
		return ret;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int tops[] = {1, 2, 3, 4, 6};
	int bottoms[] = {6, 6, 6, 6, 5};
	fprintf(stdout, "%d\n", rotations_min(tops, sizeof(tops) / sizeof (tops[0]), bottoms, sizeof(bottoms) / sizeof(bottoms[0])));
	return EXIT_SUCCESS;
}
