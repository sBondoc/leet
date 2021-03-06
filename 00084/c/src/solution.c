#include <stdio.h>
#include <stdlib.h>

int area_max(int *heights, int count_heights)
{
	int ret = 0;
	for (int i = 0; i < count_heights; i++)
	{
		int j, k;
		for (j = i; (-1 < j) && (heights[i] <= heights[j]); j--);
		j++;
		for (k = i; (k < count_heights) && (heights[i] <= heights[k]); k++);
		k--;
		if (ret < heights[i] * (k - j + 1))
		{
			ret = heights[i] * (k - j + 1);
			#ifdef DEBUG
			printf("New max: %d from %d to %d on %d\n", ret, j, k, i);
			#endif
		}
	}
	return ret;
}

int main(int argv, char **argc)
{
	int heights[] = {2, 1, 5, 6, 2, 3};
	printf("Max area = %d\n", area_max(heights, 6));
	return EXIT_SUCCESS;
}
