#include<cstdio>
int day = 0;
int a, b;
int main()
{
	int arr[4][6];
	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	}
	while (1)
	{
		day++;
		for (a = 0; a < n; a++)
		{
			for (b = 0; b < m; b++)
			{
				if (arr[a][b] == day)
				{
					if (arr[a][b + 1] == 0 && (b + 1 != 6))//������
					{
						arr[a][b + 1] = day + 1;//�湮
					}
					if (arr[a][b - 1] == 0 && (b - 1 != -1))//����
					{
						arr[a][b - 1] = day + 1;//�湮
					}
					if (arr[a + 1][b] == 0 && (a + 1 != 4))//�Ʒ�
					{
						arr[a + 1][b] = day + 1;//�湮
					}
					if (arr[a - 1][b] == 0 && (a - 1 != -1))//��
					{
						arr[a - 1][b] = day + 1;//�湮
					}
				}
			}
		}
		int flag = 0;
		for (a = 0; a < n; a++)
		{
			for (b = 0; b < m; b++)
			{
				if (arr[a][b] != 0)
					flag++;
			}
		}
		if (flag == 24)
			break;
	}
	printf("%d", day);
}