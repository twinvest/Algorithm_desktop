#include<stdio.h>
int main()
{
	int number;
	while (1)
	{
		printf("숫자를 입력하세요 : ");
		scanf("%d", &number);
		if (number >= 1 && number <= 10)
			break;
		printf("1과 10사이의 숫자만을 입력하세요!\n");
	}
	printf("입력한 숫자는 %d. 옳바른 숫자를 입력했습니다.\n", number);
}