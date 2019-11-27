#include<stdio.h>


int main(void)
{
	int num, p;
	int arr[100] = { 0 };


	printf("값 입력 : ");
	scanf("%d", &num);

	printf("십진수 %d의 이진수 변환.\n", num);

	for (p = 0; ; p++)
	{
		printf("%d.......%d\n", num, num % 2);

		arr[p] = num % 2;
		num = num / 2;
		

		if (num == 0)
			break;
	}

	while (p >= 0)
	{
		printf("%d", arr[p]);
			p--;
	}
}