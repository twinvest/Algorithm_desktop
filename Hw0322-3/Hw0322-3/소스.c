#include<stdio.h>

int fib(int n);

int main(void)
{
	int i, num;
	printf("어디까지 알아볼까요? : ");
	scanf("%d", &num);
	for (i = 0; i < num; i++) 
	{
		printf("%d\t", fib(i));
	}
	printf("\n");
}

int fib(int n)
{
	if (n < 2) return n;

	int i, temp;
	int cur = 1;
	int last = 0;

	
		for (i = 2; i<=n; i++)
		{

			temp = last + cur;
			last = cur;
			cur = temp;
		}
		return temp;
	
}