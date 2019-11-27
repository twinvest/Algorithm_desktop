#include<stdio.h>


int main(void)
{
	int num;

	printf("값 입력 : ");
	scanf("%d", &num);;
	printf("십진수 %d를 이진수로 변환.\n", num);

	
	
	for (int i = 0; ; i++)
	{
		
		if (num / 2 == 1)
		{
			printf("%d......%d\n", num, num % 2);
			break;
		}
		
		printf("%d......%d\n", num, num % 2);
		num = num / 2;
		
	
	}
	

	return 0;
	
	
}