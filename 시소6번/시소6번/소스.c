#include<stdio.h>
int main()
{
	int month = 0; //��
	float current_money = 0;//����
	float rate = 0; //����
	float expense = 0;
	int i = 0;
	
	do {
		printf("������ �Է��ϼ��� : ");
		scanf("%f", &current_money);
		printf("�������� �Է��ϼ��� : ");
		scanf("%f", &rate);
		printf("�� ������ �Է��ϼ��� : ");
		scanf("%f", &expense);
		if (expense < (current_money * rate))
			printf("���⺸�� ���ڷ� ����� ���� �� ������ ���� ���� �ʽ��ϴ�. ���� ���ѷ����� �����ϱ� �ٽ� �Է��ϼ���!\n\n");
			
	} while (expense < (current_money * rate));//���ѷ��� ���� �߻��ϴ°�? ���������� ��(��ϱ�)���� ������ ��(����)�� ���� �� ���� ���� �����ϱ� ���ѷ���. 
	
	while (1)
	{
		++i;
		current_money = current_money - expense; //��ϱ��� ���� �����ٰ� ����
		current_money = current_money + (current_money * rate); //�׸��� �Ѵ��Ŀ� ���� �߻�. �ٵ� ���ڰ� ���� �߻��ϰ� ��ϱ��� ���������� ���ѷ�����.
		printf("���� �ݾ� : %lf\n ����Ƚ�� : %d\n", current_money, i);
		++month;

		if (current_money < 0)
			break;
	}

	printf("%d�� %d�� �Ŀ� ���Ǿ����ϴ�.\n", month / 12, month % 12);
}