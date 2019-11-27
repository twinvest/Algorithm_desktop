#include<stdio.h>
int main()
{
	int i, j, k = 0;
	int flag = 0;
	int num = 0;
	printf("값을 입력하세요 : ");
	scanf("%d", &num);
	for (i = 0; i < num*2-1; i++)
	{
		if (i < num) {
			for (j = 0; j < num * 2 - 1; j++)
			{
				if (j < num) {//삼각형 1
					if (num - 1 - i <= j)
						printf("* ");
					else
						printf("  ");
				}
				else { //삼각형 2
					if (j < num + i)
						printf("* ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		else// i가 num보다 클때
		{
			for(j = 0; j < num * 2 -1; j++)
			{
				if (j < num)//i가 num보다 크고 j가 num보다 작은 경우의 삼각형
				{ 
					if (j+num > i)
						printf("* ");
					else
						printf("  ");
				}
				else //i가 num보다 크고 j가 num보다 큰 경우의 삼각형
				{
					if (j<=2*num-i+1)
						printf("* ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		}
	}