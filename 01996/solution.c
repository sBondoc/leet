#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int number_weak_characters(int **properties, int size_properties, int size_properties_col)
{
	int n = 0;
	for (int i = 0; i < size_properties; i++)
	{
		for (int j = 0; j < size_properties; j++)
		{
			if ((properties[i][0] < properties[j][0]) && (properties[i][1] < properties[j][1]))
			{
				n++;
				break;
			}
		}
	}
	return n;
}

int main(int argc, char **argv)
{
	int p0[2] = {1, 5};
	int p1[2] = {10, 4};
	int p2[2] = {4, 3};
	int *p[3] = {p0, p1, p2};
	printf("Number of weak characters: %d\n", number_weak_characters(p, SIZE_PROPERTIES, SIZE_PROPERTIES_COL));
	return EXIT_SUCCESS;
}
