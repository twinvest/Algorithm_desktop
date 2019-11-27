#include <stdio.h>
#include <stdlib.h>


int f(double n);

int main(void)
{
	double n;
	printf("숫자를 입력하세요: ");
	scanf("%lf", &n);
	printf("%d\n", f(n));

	return 0;
}

int f(double n)
{
	int flag = 0;
	double result = n;

	while (1)
	{
		result = result - 1;
		flag++;
		if (result < 1)
			break;
	}
	if (result > 0.5)
		flag++;

	return flag;

}