#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

int to_int(char *s)
{
	bool start = false, neg = false;
	long int ret = 0;
	for (int i = 0; (s[i] != '\0') && !(start && !isdigit(s[i])); i++)
	{
		if (start)
		{
			ret = 10 * ret + s[i] - 48;
		}
		else if (isdigit(s[i]))
		{
			start = true;
			ret = 10 * ret + s[i] - 48;
		}
		else if (s[i] == '-')
		{
			start = true;
			neg = true;
		}
		else if (s[i] == '+')
		{
			start = true;
		}
		else if (s[i] != ' ')
		{
			return 0;
		}
		if (!neg && (INT_MAX < ret))
		{
			return INT_MAX;
		}
		else if (neg && (-1 * ret < INT_MIN))
		{
			return INT_MIN;
		}

	}
	return ret * ((neg) ? -1 : 1);
}

int main(int argc, char *argv[])
{
	printf("%d\n", to_int("     -1234 asdf"));
	return EXIT_SUCCESS;
}
