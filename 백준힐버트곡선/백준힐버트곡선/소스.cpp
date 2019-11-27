#include<iostream>
#include<cstdio>
int size;
int number;
int flag;
int real_y, real_x, real_size;
int arr[2][2] = {1,2,3,4};
void search(int y, int x, int size)
{
	if (size == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				flag++;
				if (number == arr[i][j])
				{
					printf("%d %d\n", real_x, real_y);
				}
			}
		}
	}
	else
	{
		if (number <= (size / 2)*(size / 2) && number >= 1) //1~4
		{
			real_x += size / 2;
			search(size / 2, x, size / 2);
		}
		if (number <= 2 * ((size / 2)*(size / 2)) && number > (size / 2)*(size / 2))//5~8
		{
			number -= (size / 2 * size / 2);
			search(y, x, size / 2);
		}
		if (number <= 3 * ((size / 2)*(size / 2)) && number > 2 * ((size / 2)*(size / 2)))//9~12
		{
			real_y += size / 2;
			number -= (size / 2 * size / 2) * 2;
			search(y, size / 2, size / 2);
		}
		if (number <= 4 * ((size / 2)*(size / 2)) && number > 3 * ((size / 2)*(size / 2)))//13~16
		{
			real_x += size / 2;
			real_y += size / 2;
			number -= (size/2 * size/2) * 3;
			search(size / 2, size / 2, size / 2);
		}
	}
}
int main(void)
{
	scanf("%d", &size);
	scanf("%d", &number);
	real_size = size;
	search(0, 0, size);
}