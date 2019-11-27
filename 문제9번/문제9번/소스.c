//세로출력
#include<stdio.h>
int main()
{
	int size = 0;
	int i, j = 0;
	int a, b = 0;
	printf("size를 입력하세요 : ");
	scanf("%d", &size);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	printf("\n");
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size; b++)
		{
			if (a == 0 || a == (size - 1) || b == 0 || b == (size - 1))
				printf("* ");
			else
				printf("  ");

		}
		printf("\n");
	}
}