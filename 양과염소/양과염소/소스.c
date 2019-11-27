#include<stdio.h>

int main()
{
	int a; //양이 섭취
	int b; //염소가 섭취
	int n; //양 염소 합친 수
	int w; //전체 처먹은 양
	int sheep_num;
	int goat_num;
	
	int arr[3];
	int arr2[3];
	
	scanf("%d %d %d %d", &a, &b, &n, &w);
	
	arr[0] = a;
	arr[1] = b;
	arr[2] = w;
	
	arr2[0] = 1;
	arr2[1] = 1;
	arr2[2] = n;

	if (arr[0] != arr2[0])
	{
		arr2[0] = arr2[0] * arr[0];
		arr2[1] = arr2[1] * arr[0];
		arr2[2] = arr2[2] * arr[0];
	}
	
	
	
	if (arr[1]-arr2[1] == 1)
	{
		goat_num = arr[2] - arr2[2];
		sheep_num = n - goat_num;
	}
	else //양의 수가 1이 아닐때
	{
		int a = arr[1] - arr2[1];
		int b = arr[2] - arr2[2];
		if (a >= 0) //양수
		{
			if (b%a != 0)
			{
				goat_num = -1;
			}
			else
			{
				goat_num = b / a;
				sheep_num = n - goat_num;
			}
		}
	
		else //음수
		{
			a = a * -1;
			b = b * -1;
			
			if (b%a != 0)
			{
				goat_num = -1;
			}
			else
			{
				goat_num = b / a;
				sheep_num = n - goat_num;
			}
		}
	}







	if (goat_num == -1 || goat_num==0 || sheep_num==0)
	{
		printf("-1");
	}
	else
	{
		printf("%d ", sheep_num);
		printf("%d", goat_num);
	}
}