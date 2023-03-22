#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
bool in_bounds(int size, int n)
{
	return (0 <= n) && (n < size);
}
bool empty_plot(int *flowerbed, int flowerbed_size, int n)
{
	return !in_bounds(flowerbed_size, n) || flowerbed[n] == 0;
}
bool valid_plot(int *flowerbed, int flowerbed_size, int n)
{
	return 
		(flowerbed[n] == 0) &&
		empty_plot(flowerbed, flowerbed_size, n - 1) &&
		empty_plot(flowerbed, flowerbed_size, n + 1);
}
bool can_place_flowers(int *flowerbed, int flowerbed_size, int n)
{
	int flowers_placed = 0;
	for (int i = 0; i < flowerbed_size; i++)
	{
		if (valid_plot(flowerbed, flowerbed_size, i))
		{
			flowers_placed++;
			if (n <= flowers_placed)
			{
				return true;
			}
		}
	}
	return false;
}
int main(void)
{
	int flowerbed[] = {0, 0, 1, 0, 0};
	int size = sizeof(flowerbed) / sizeof(flowerbed[0]);
	fprintf(stdout, "%s\n", (can_place_flowers(flowerbed, size, 2)) ? "true" : "false");
	return EXIT_SUCCESS;
}
