#include<stdio.h>

int main(void)

{
	int i, n, sum;

	printf("n�� �� ���� �Է��Ͻÿ�.");
	scanf("%d", &n);

	sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum = sum + i;

		
	}
	printf("1���� %d������ ��:%d\n ", n, sum);

	return 0;

}