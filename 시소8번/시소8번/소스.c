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
	
	printf("MAX값을 입력하세요 : ");
	scanf("%d", &max);
	while (1) {
		printf("MAX값보다 작거나 같은 임의의 정수 값을 입력하세요 : ");
		scanf("%d", &num);
		if (num <= max) break;
	}
	max_print_even(num, max);
}