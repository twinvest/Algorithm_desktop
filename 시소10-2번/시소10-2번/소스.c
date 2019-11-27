#include <stdio.h>



void main()

{
	int num = 0;
	printf("값을 입력하세요: ");
	scanf("%d", &num);

	int i, j, k;


	for (i = 0; i<num; i++)

	{

		for (k = num; k>i; k--)

			printf(" ");

		for (j = 1; j<(i * 2); j++)

			printf("*");



		printf("\n");

	}



	for (i = 0; i<num; i++)

	{

		for (k = 0; k<i + 2; k++)

			printf(" ");

		for (j = num; j>(i * 2); j--)

			printf("*");



		printf("\n");

	}

}