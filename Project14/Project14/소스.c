#include<stdio.h>


int main(void)
{
	int num;

	printf("�� �Է� : ");
	scanf("%d", &num);;
	printf("������ %d�� �������� ��ȯ.\n", num);

	
	
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