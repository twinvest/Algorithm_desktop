#include<stdio.h>

int main(void)
{
	int i, j;
	int num;
	int pos;
	printf("�迭�� ���̸� ���Ͻÿ�");
	scanf("%d", &num);

	int(*a)[4];
	a = (int*)malloc(sizeof(int)*num*num);

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			scanf("%d", &a[i][j]);

		}
	}

	


	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("%d\t", a[i][j]);
		}
	}

	free(a);
	return 0;


}