#include<cstdio>
#include<iostream>
int main()
{
	int flag = 0;
	int arr[7] = { 64, 32, 16, 8, 4, 2, 1 };
	int x;
	int max;
	scanf("%d", &x);
	while (x != 0)
	{
		for (int i = 0; i<(sizeof(arr) / sizeof(int)); i++) 
		{
			if (x >= arr[i])
			{
				max = arr[i];
				x = x - max;
				flag++;
				break;
			}
		}
			
	}
	printf("%d", flag);
}
