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

	printf("x ���� �Է����ּ���~~����");
	scanf("%d", &x);
	printf("y ���� �Է����ּ���~~����");
	scanf("%d", &y);

	result3 = (6 * x*x) + (11 * x);
	printf("%d\n", result3);

	
	Jisuhamsu(x, y);

	printf("�� ���� �ϳ��� ���� �Է��� �����Դϴ�.\n");
	printf("�ϳ��� ���� �Է����ּ���~~! : ");
	scanf("%d", &num);


	if (num % 2 == 0)
		printf("¦����~~\n");
	else
		printf("Ȧ����~~\n");

	twinvest();
	switchmoon();




	return 0;
}


int twinvest(void)
{
	int num;
	printf("�����Է� : ");
	scanf("%d", &num);

	if (num < 0)
		printf("�Է°��� 0���� �۾ƿ�\n");
	if (num > 0)
		printf("�Է°��� 0���� Ŀ��\n");
	if (num == 0)
		printf("�Է� ���� 0�� �Է��߳׿�\n");
}

int switchmoon(void)
{
	int num;
	printf("1�̻� 4���� ���� �Է� : ");
	scanf("%d", &num);

	switch (num)
	{
	case 1: 
	case 2:
		printf("2�� ���̽� ����\n");
		break;
	case 3:
		printf("3�� ���̽� ����\n");
		break;
	case 4:
		printf("4�� ���̽� ����\n");
		break;
	default:
		printf("1�̻� 4���� �����Է��Ϸ���?�Ѥ�");
			

	}
	return 0;

}