#include<stdio.h>

int main()
{
	int a, b, c, d;
	printf("����1\n����2\n����3\n������4\n");
	printf("� ������ �Ͻðڽ��ϱ�?");
	scanf("%d", &a);
	printf("�μ��� �Է��ϼ���");
	scanf("%d", &b);
	scanf("%d", &c);

	switch (a)
	{
	case 1:
		d = b + c;
		printf(d);
	case 2:
		d = b - c;
		printf(d);
	case 3:
		d = b * c;
		printf(d);
	case 4:
		d = b / c;
		printf(d);
	default:
		break;
	}
}