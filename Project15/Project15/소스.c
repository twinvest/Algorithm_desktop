#include<stdio.h>


int main(void)
{
	int num, p;
	int arr[100] = { 0 };


	printf("�� �Է� : ");
	scanf("%d", &num);

	printf("������ %d�� ������ ��ȯ.\n", num);

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