#include <stdlib.h>
#include <stdio.h>

int remove_covered_intervals(int **intervals, int size_intervals, int *size_intervals_cols)
{
	int ret = size_intervals;
	for (int i = 0; i < size_intervals; i++)
	{
		for (int j = 0; j < size_intervals; j++)
		{
			if ((i != j) && (intervals[j][0] <= intervals[i][0]) && (intervals[i][1] <= intervals[j][1]))
			{
				ret--;
				break;
			}
		}
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int intervals0[] = {1, 4};
	int intervals1[] = {3, 6};
	int intervals2[] = {2, 8};
	int size_intervals_cols = 2;
	int *intervals[] = {intervals0, intervals1, intervals2};
	printf("%d\n", remove_covered_intervals(intervals, 3, &size_intervals_cols));
	return EXIT_SUCCESS;
}
