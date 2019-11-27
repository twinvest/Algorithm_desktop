#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num;
	double num1;
	double num2;
	double result;
	
	printf("이 계산기는 쓰레기입니다.\n");
	printf("그러니까 두개의 수만 입력해주세용ㅠㅠ\n");
	scanf("%lf %lf", &num1, &num2);

	printf("선택해 마!\n");
	printf("1. 덧셈\n");
	printf("2. 뺄셈\n");
	printf("3. 곱셈\n");
	printf("4. 나눗셈\n");
	scanf("%d", &num);
	
	switch (num)
	{
	case 1:
		result = num1 + num2;
		break;
	case 2:
		result = num1 - num2;
		break;
	case 3:
		result = num1 * num2;
		break;
	case 4:
		result = num1 / num;
		break;
	default:
		printf("덧샘1번이야 뺼셈2번 곱셈3 나눗셈4만 입력해라!!");

	}

	printf("계산의 결과는 %f 입니다.", result);
	return 0;

}