#include<stdio.h>

int main()
{
	int num;
	int arr[100];
	int*ar1 = arr + 99;

	printf("2������ ��ȯ�� 10������ ���� �Է��غ����� : ");
	scanf_s("%d", &num);


	for (int i = 0; i < 100; i++)
	{
		arr[i] = 0;
	}


	for (int i = 0; ; i++)
	{

		if (num == 1)// �������
		{
			arr[i] = 1;
			break;
		}
		if (num / 2 == 1)
		{
			if (num % 2 == 0)
			{
				arr[i] = 0;
				arr[i + 1] = 1;
			}
			else {
				arr[i] = 1;
				arr[i + 1] = 1;
			}
			break;
		}// ������� ���λ��� �ֳ�? 2������ϸ� �ȵǴϱ�
		if (num % 2 == 0)
		{
			arr[i] = 0;
			num = num / 2;
		}

		else if (num % 2 != 0)
		{
			arr[i] = 1;
			num = num / 2;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		printf("%d", *ar1);
		ar1--;
	}

	return 0;


}