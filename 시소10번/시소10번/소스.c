#include<stdio.h>
int main()
{
	int i, j, k = 0;
	int flag = 0;
	int num = 0;
	printf("���� �Է��ϼ��� : ");
	scanf("%d", &num);
	for (i = 0; i < num*2-1; i++)
	{
		if (i < num) {
			for (j = 0; j < num * 2 - 1; j++)
			{
				if (j < num) {//�ﰢ�� 1
					if (num - 1 - i <= j)
						printf("* ");
					else
						printf("  ");
				}
				else { //�ﰢ�� 2
					if (j < num + i)
						printf("* ");
					else
						printf("  ");
				}
			}
			printf("\n");
		}
		else// i�� num���� Ŭ��
		{
			for(j = 0; j < num * 2 -1; j++)
			{
				if (j < num)//i�� num���� ũ�� j�� num���� ���� ����� �ﰢ��
				{ 
					if (j+num > i)
						printf("* ");
					else
						printf("  ");
				}
				else //i�� num���� ũ�� j�� num���� ū ����� �ﰢ��
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