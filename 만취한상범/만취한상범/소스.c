#include<stdio.h>
int main(void)
{
	int flag=0; //Ż���
	int i = 0; //���̽�
	int n = 0; //���� ����.         0�� ������. 1�� ������.
	int arr[101] = { 0 };
	scanf("%d", &i); //���̽�
	

	
	while (i--) //i�� ���̽���.
	{

		scanf("%d", &n); //�氳��
		for (int j = 1; j <= n; j++) //����
		{
			for (int z = 1; z <= n; z++)//�漳��
			{
				if (arr[z*j] == 0)
					arr[z*j] = 1;
				else
					arr[z*j] = 0;
			}
		}

		for (int j = 1; j <= n; j++)
		{
			if (arr[j] == 1)
				arr[j] = 0;
				++flag;
		}
		printf("%d\n", flag);


	}

	return 0;
}