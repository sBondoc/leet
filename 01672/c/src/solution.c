#include <stdio.h>
#include <stdlib.h>

int wealth_max(int **accounts, int size_accounts, int *size_accounts_col)
{
	int ret = 0;
	for (int i = 0; i < size_accounts; i++)
	{
		int sum = 0;
		for (int j = 0; j < *size_accounts_col; j++)
		{
			sum += accounts[i][j];
		}
		if (ret < sum)
		{
			ret = sum;
		}	
	}
	return ret;
}

int main(int argc, char **argv)
{
	int accounts_0[] = {1, 2, 3};
	int accounts_1[] = {3, 2, 1};
	int *accounts[3];
	accounts[0] = accounts_0;
	accounts[1] = accounts_1;
	int size_accounts_col = 3;
	printf("%d\n", wealth_max(accounts, 2, &size_accounts_col)); 
	return EXIT_SUCCESS;
}
