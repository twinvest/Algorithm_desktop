#include<stdio.h>

int main(void)

{
	int i, n, sum;

	printf("n에 들어갈 값을 입력하시오.");
	scanf("%d", &n);

	sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum = sum + i;

		
	}
	printf("1부터 %d까지의 합:%d\n ", n, sum);

	return 0;

}