#include<stdio.h>
void max_print_even(int max)
{
	for (int i = 2; i <= max; i+=2)
	{
		printf("%d ", i);
	}
}

int main()
{
	int max = 0;
	printf("MAX���� �Է��ϼ��� : ");
	scanf("%d", &max);
	max_print_even(max);
}