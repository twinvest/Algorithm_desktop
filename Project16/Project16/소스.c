#include <stdio.h>

int main(void)
{
	int i, j, k;

	for (i = 0; i < 5; i++)
	{
		for (k = 5; k > i; k--)
			printf(" ");
		for (j = 1; j < (i*2); j++)
			printf("*");

		printf("\n");
	}


	for (i = 0; i < 5; i++)
	{
		for (k = 0; k < i + 2; k++)
			printf(" ");
		for (j = 5; j > (i * 2); j--)
			printf("*");
		
     	printf("\n");
	}
}

