#include<stdio.h>
void max_print_even(int num, int max)
{
	for (int i = num; i <= max; i += num)
	{
		printf("%d ", i);
	}
}

int main()
{
	int max = 0;
	int num = 0;
	
	printf("MAX���� �Է��ϼ��� : ");
	scanf("%d", &max);
	while (1) {
		printf("MAX������ �۰ų� ���� ������ ���� ���� �Է��ϼ��� : ");
		scanf("%d", &num);
		if (num <= max) break;
	}
	max_print_even(num, max);
}