#include<stdio.h>
int main()
{
	
	int num;
	printf("������ �Է��Ͻÿ� : ");
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