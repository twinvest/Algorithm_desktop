#include<stdio.h>
#include<stdlib.h>


int dfs(int*arr, int a, int b)
{
	if (arr[a - 1][b] == 1)
		dfs(&arr[a - 1][b], a - 1, b);
	
	if (arr[a + 1][b] == 1) 
	if(arr[a][b - 1] == 1) 
	if(arr[a][b + 1] == 1 )
	if( arr[a - 1][b - 1]) == 1) 
	if(arr[a - 1][b + 1] == 1) 
	if( arr[a + 1][b - 1] == 1) 
	if(arr[a + 1][b + 1] == 1) 
		dfs()
}

int main()
{
	int arr[50][50];
	int i, j;
	scanf("%d", &i);
	scanf("%d", &j);
	for (int a = 0; a < i; a++)
	{
		for (int b = 0; b < j; b++)
			scanf("%d", &arr[a][b]);
	}
	
	for (int a = 0; a < i; a++)
	{
		for (int b = 0; b < j; b++)
		{
			if (a - 1 > 0 && a + 1 != i && b - 1 > 0 && b + 1 != j)  //�̺κ��� ���� ����� �κ���.
			{
				if (arr[a][b] == 1 && (arr[a-1][b]==1 || arr[a+1][b]==1 || arr[a][b-1]==1 || arr[a][b+1]==1 ||arr[a-1][b-1])==1 || arr[a-1][b+1]==1 || arr[a+1][b-1]==1 || arr[a+1][b+1]==1 )//�ڱ��ڽ��� �����鼭 ��, ��, ����, ������, �׸��� 4���� �밢�� �� �ϳ��� 1�� �ִٸ�!!
				{
					dfs(&arr[a][b], a, b);
				}

			}
			

		}
	}
	
	
	
	
	for (int a = 0; a < i; a++)
	{
		printf("\n");
		for (int b = 0; b < j; b++)
			printf("%d", arr[a][b]);
	}


}