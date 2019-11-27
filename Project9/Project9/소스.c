#include<stdio.h>

void Jisuhamsu(int a, int b)
{
	int x, y, result1, result2;
	x = a;
	y = b;

	result1 = (6 * x*x*x) + (11 * x);
	result2 = (11 * y*y) + 21;
	printf("%d >= %d", result1, result2);

	return;


}


int main(void)
{
	int x;
	int y;
	int result1;
	
	printf("x 값을 입력해주세용~~ㅎㅎ");
	scanf("%d", &x);
	printf("y 값을 입력해주세용~~ㅎㅎ");
	scanf("%d", &y);

	
	result1 = (6 * x*x) + (11 * x);
	
	printf("%d", result1);

	Jisuhamsu(x, y);
	
	
	return 0;


}


