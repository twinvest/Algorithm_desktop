#include<stdio.h>

void Jisuhamsu(int a, int b)
{
	int x, y, result1, result2;
	x = a;
	y = b;

	result1 = (6 * x*x*x) + (11 * x);
	result2 = (11 * y*y) + 21;
	printf("%d >= %d\n", result1, result2);

	return;
	
}

int main(void)
{
	int x;
	int y;
	int num;
	int result3;

	printf("x 값을 입력해주세용~~ㅎㅎ");
	scanf("%d", &x);
	printf("y 값을 입력해주세용~~ㅎㅎ");
	scanf("%d", &y);

	result3 = (6 * x*x) + (11 * x);
	printf("%d\n", result3);

	
	Jisuhamsu(x, y);

	printf("자 이제 하나의 수를 입력할 차례입니다.\n");
	printf("하나의 수를 입력해주세욧~~! : ");
	scanf("%d", &num);


	if (num % 2 == 0)
		printf("짝수맨~~\n");
	else
		printf("홀수맨~~\n");

	twinvest();
	switchmoon();




	return 0;
}


int twinvest(void)
{
	int num;
	printf("정수입력 : ");
	scanf("%d", &num);

	if (num < 0)
		printf("입력값이 0보다 작아용\n");
	if (num > 0)
		printf("입력값이 0보다 커용\n");
	if (num == 0)
		printf("입력 값을 0을 입력했네용\n");
}

int switchmoon(void)
{
	int num;
	printf("1이상 4이하 정수 입력 : ");
	scanf("%d", &num);

	switch (num)
	{
	case 1: 
	case 2:
		printf("2번 케이스 선택\n");
		break;
	case 3:
		printf("3번 케이스 선택\n");
		break;
	case 4:
		printf("4번 케이스 선택\n");
		break;
	default:
		printf("1이상 4이하 정수입력하랬지?ㅡㅡ");
			

	}
	return 0;

}