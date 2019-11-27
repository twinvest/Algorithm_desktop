#include<stdio.h>
int arr[50][50] = { 3, };
int col; 
int row; 
void dfs(int p[][50], int i, int j)
{
	if ((i - 1 != -1) && p[i - 1][j] == 1)  //위
	{
		p[i - 1][j] = 2;
		dfs(p, i - 1, j);
	}
	if ((i + 1 != row) && p[i + 1][j] == 1)  //아래
	{
		p[i + 1][j] = 2;
		dfs(p, i + 1, j);
	}

	if ((j - 1 != -1) && p[i][j - 1] == 1) //왼쪽
	{
		p[i][j - 1] = 2;
		dfs(p, i, j - 1);
	}

	if ((j + 1 != col) && p[i][j + 1] == 1)  //오른쪽
	{
		p[i][j + 1] = 2;
		dfs(p, i, j + 1);
	}

	if ((i - 1 != -1) && (j - 1 != -1) && p[i - 1][j - 1] == 1)  //11시
	{
		p[i - 1][j - 1] = 2;
		dfs(p, i - 1, j - 1);
	}

	if ((i - 1 != -1) && (j + 1 != col) && p[i - 1][j + 1] == 1) //1시
	{
		p[i - 1][j + 1] = 2;
		dfs(p, i - 1, j + 1);
	}


	if ((i + 1 != row) && (j + 1 != col) && p[i + 1][j + 1] == 1) // 5시
	{
		p[i + 1][j + 1] = 2;
		dfs(p, i + 1, j + 1);
	}


	if ((i + 1 != row) && (j - 1 != -1) && p[i + 1][j - 1] == 1)  //7시
	{
		p[i + 1][j - 1] = 2;
		dfs(p, i + 1, j - 1);
	}

}
int main()
{
	while (1)
	{
		int flag = 0;

		scanf("%d", &col);
		scanf("%d", &row);
		if (col == 0 && row == 0)
			exit(0);

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				scanf("%d", &arr[i][j]);
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				if (arr[i][j] == 1)
				{
					arr[i][j] = 2;
					dfs(arr, i, j);
					flag++;
				}
		}
		printf("%d\n", flag);
	}
	/*for (int i = 0; i < row; i++)
	{
		printf("\n");
		for (int j = 0; j < col; j++)
			printf("%d ", arr[i][j]);
	}*/
}