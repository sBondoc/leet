#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int complement_bitwise(int n)
{
	int b = 0;	
	uint32_t m = (uint32_t) n;
	if (n == 0)
	{
		return 1;
	}
	while (m < UINT32_C(1) << 31)
	{
		b++;
		m <<= 1;
	}
	m = ~m;
	m >>= b;
	return m;
}

int main(int argc, char *argv[])
{
	printf("%d\n", complement_bitwise(5));
	return EXIT_SUCCESS;
}
