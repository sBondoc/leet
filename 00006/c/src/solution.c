#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_arr(int *arr, int size)
{
	printf("{");
	for (int i = 0; i < size - 1; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("%d}\n", arr[size - 1]);
}

char *convert(char *s, int rows)
{	
	int len = strlen(s);
	char *ret = NULL;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
	{
		perror("Failed to malloc \"ret\". Try downloading more RAM.\n");
		return NULL;
	}
	if (1 < rows)
	{
		int map_row[len];
		int k = 0;
		bool up = false;	
		for (int i = 0; i < len; i++)
		{
			map_row[i] = k;
			k += (up) ? -1 : 1;
			if ((!up && (k == rows - 1)) || (up && (k == 0)))
			{
				up = !up;
			}
		}
		k = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (map_row[j] == i)
				{
					ret[k++] = s[j];
				}
			}
		}

	}
	else
	{
		memcpy(ret, s, len * sizeof(char));
	}
	ret[len] = '\0';
	return ret;
}

int main(int argc, char *argv[])
{
	char **excess = NULL;
	char *s = (argc < 3) ? "PAYPALISHIRING" : argv[1];
	int rows = (argc < 3) ? 3 : strtol(argv[2], excess, 10);
	char *lines = convert(s, rows);
	printf("%s\n", lines);
	free(lines);
	return EXIT_SUCCESS;
}
