#include<stdio.h>
int main()
{
	int month=0;
	float current_money = 10000;
	int i = 0;

	while (1)
	{
		++i;
		current_money = current_money - 500; //��ϱ��� ���� �����ٰ� ����
		current_money = current_money + (current_money * 0.05); //�׸��� �Ѵ��Ŀ� ���� �߻�. �ٵ� ���ڰ� ���� �߻��ϰ� ��ϱ��� ���������� ���ѷ�����.
		printf("���� �ݾ� : %lf\n ����Ƚ�� : %d\n", current_money, i);
		++month;
		
		if (current_money < 0)
			break;
	}//���ѷ��� ���� �߻��ϴ°�? ���������� ��(��ϱ�)���� ������ ��(����)�� ���� �� ���� ���� �����ϱ� ���ѷ���. 

	printf("%d�� %d�� �Ŀ� ���Ǿ����ϴ�.\n",month/12, month%12);
}