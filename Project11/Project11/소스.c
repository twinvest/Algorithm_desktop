#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num;
	double num1;
	double num2;
	double result;
	
	printf("�� ����� �������Դϴ�.\n");
	printf("�׷��ϱ� �ΰ��� ���� �Է����ּ���Ф�\n");
	scanf("%lf %lf", &num1, &num2);

	printf("������ ��!\n");
	printf("1. ����\n");
	printf("2. ����\n");
	printf("3. ����\n");
	printf("4. ������\n");
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
		printf("����1���̾� �E��2�� ����3 ������4�� �Է��ض�!!");

	}

	printf("����� ����� %f �Դϴ�.", result);
	return 0;

}