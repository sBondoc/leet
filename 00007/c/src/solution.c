#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define SIZE 5

int reverse(int x)
{
	if ((x == INT_MIN) || (x == INT_MAX))
	{
		return 0;
	}
	int ret = 0;
	for (int n = x * (x < 0 ? -1 : 1); 0 < n; n /= 10)
	{
		if ((ret == 0) || (10 <= INT_MAX / ret))
		{
			ret *= 10; 
			ret += n % 10;
			printf("ret = %d n = %d\n", ret, n);
		}
		else
		{
			return 0;
		}
	}	
	return ret * (x < 0 ? -1 : 1);
}

int main(int argc, char *argv[])
{
	int tests[SIZE] = {123, -123, 120, INT_MIN, INT_MAX};
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d reversed is %d\n", tests[i], reverse(tests[i]));
	}
	return EXIT_SUCCESS;
}
