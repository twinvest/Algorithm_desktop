#include<stdio.h>

int main()
{
	int flag=0;
	int n=0;
	double number=0;
	double s=0;
	double arr[100];

	while (number<3 || 10000<number) //�Է�����
	{
		scanf("%lf", &number);
	}
	
	while (number > s) //n���ϱ�.
	{
		++n;
		s = (0.5*n*n) + (0.5*n);
		arr[n] = s;
	}
	if (arr[n] > number) //�Է¹��� �� ���� �����鼭 �Է¹��� ���� ���� ����� �ﰢ��
		--n;
	
	double remainder = number - arr[n]; //�Է¹��� ���� �ﰢ���� ��.
	

	for (int i = 1; i <= n; i++)
	{
		if (remainder == arr[i] || number==6)  //���� ������ �ִٸ� ������ 2���� ǥ�� ����.
		{
			++flag;
		}
	}

	if (flag)
	{
		printf("2���� ǥ�� ����.\n");
	}
	else
	{
		printf("3���� ǥ�� ����\n");
	}
	/*printf("n�� �� : %d\n", n);
	printf("s�� �� : %lf\n", s);
	printf("number�� �� : %lf\n", number);
	printf("reaminder�� �� : %lf\n", remainder);
	printf("%d", arr[0]);*/
}