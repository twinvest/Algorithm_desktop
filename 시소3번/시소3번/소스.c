#include<stdio.h>
int main()
{
	int number;
	while (1)
	{
		printf("���ڸ� �Է��ϼ��� : ");
		scanf("%d", &number);
		if (number >= 1 && number <= 10)
			break;
		printf("1�� 10������ ���ڸ��� �Է��ϼ���!\n");
	}
	printf("�Է��� ���ڴ� %d. �ǹٸ� ���ڸ� �Է��߽��ϴ�.\n", number);
}