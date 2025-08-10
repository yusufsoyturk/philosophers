#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *a = "2147483649";
	long b = 2147483649;

	printf("%ld\n", atol(a));
}