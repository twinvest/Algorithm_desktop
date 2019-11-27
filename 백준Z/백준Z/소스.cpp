#include<cstdio>
#include<math.h>
int N, r, c, flag;
void search(int y, int x, int size)
{
	if (size == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j <2; j++)
			{
				flag++;
				if (i == r && j == c)
				{
					printf("%d", flag - 1);
				}
			}
		}
	}
	else
	{
		if (r < size / 2 && c < size / 2) //1사분면
		{
			search(y, x, size / 2);
		}
		else if (r < size / 2 && c >= size / 2) //2사분면
		{
			//r = r - size / 2;
			c = c - size / 2;
			flag = (flag + ((size / 2)*(size / 2)));
			search(y, x + size / 2, size / 2);
		}
		else if (r >= size / 2 && c < size / 2) //3사분면
		{
			r = r - size / 2;
			//c = c - size / 2;
			flag = (flag + 2 * ((size / 2)*(size / 2)));
			search(y + size / 2, x, size / 2);
		}
		else if (r >= size / 2 && c >= size / 2) //4사분면
		{
			r = r - size / 2;
			c = c - size / 2;
			flag = (flag + (3 * (size / 2)*(size / 2)));
			search(y + size / 2, x + size / 2, size / 2);
		}
	}
}
int main()
{
	scanf("%d", &N);
	scanf("%d", &r);
	scanf("%d", &c);
	int size;
	size = pow(2, N);
	search(0, 0, size);
}