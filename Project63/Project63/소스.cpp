#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>

int arr[50][50];
char str[50][50];
int min = 1000000;
int max, tmp;
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str[i]);	
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (str[i][j] == 'K')
			{
				tmp = arr[i][j];
				if (min > tmp)
					min = tmp;
				if(min<tmp)
					max = tmp;
			}
		}
	}
	printf("%d", max - min);
}
