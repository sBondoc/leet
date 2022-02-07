#include <stdio.h>
#include <stdlib.h>

char difference(char *s, char *t)
{
	int sum_s = 0, sum_t = 0;
	for (int i = 0; t[i] != '\0'; i++)
	{
		sum_s += s[i];
		sum_t += t[i];
	}
	return (char) sum_t - sum_s;
}

int main(int argc, char *argv[])
{
	printf("Difference: %c\n", difference("asdf", "fadgs"));
	return EXIT_SUCCESS;
}
