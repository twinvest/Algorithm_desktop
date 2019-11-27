#include<stdio.h>
int main()
{
	
	int num;
	printf("정수를 입력하시오 : ");
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (num-i-1>j)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}