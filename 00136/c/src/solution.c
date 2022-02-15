#include <stdlib.h>
#include <stdio.h>

int singleton(int *nums, int size)
{
	int ret = 0;
	for (int i = 0; i < size; i++)
	{
		ret ^= nums[i];
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int nums[] = {2, 2, 1};
	printf("%d\n", singleton(nums, 3));
	return EXIT_SUCCESS;
}
