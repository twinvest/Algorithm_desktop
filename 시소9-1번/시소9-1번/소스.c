//가로출력
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
		printf("\n");
		for (j = 0; j < size * 2 + 1; j++) {
			if (j < size)
			{
				printf("* ");
			}
			else if (j == size)
				printf("  ");
			else
			{
				if (i == 0 || i == size - 1 || j == size + 1 || j == size * 2)
					printf("* ");
				else
					printf("  ");
			
			}
		}
	}
	printf("\n");
}