#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void BubbleSort(int arr[], int n);

int main()
{

	int num;
	int i, j;
	int arr[100][100]; // �迭����

	
	
	printf("������ �迭�� size�� �Է��ϼ���");
	scanf_s("%d", &num);
	printf("%d x %d�� �迭�� �������Դϴ�.\n", num, num);

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			arr[i][j] = rand();   //������ �迭 ���� ä������. num������ ä������.
		}
	}

	BubbleSort(arr, num);  //�ؿ������� �������ķ� ���Ľ���.

	for (i = 0; i < num; i++)  //���ĵ� �迭 ��� for��
	{
		for (j = 0; j < num; j++)
		{
			printf("%d   ", arr[i][j]);
		}
		printf("\n");
	}



	return 0;

}

void BubbleSort(int arr[][100], int n) //n�� num�� �Ǿ����.
{
	int i, j, k;
	int temp;

	//��������

	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n - 1; i++)
		{

			for (j = 0; j < (n - i) - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[k][j] = arr[k][j + 1];
					arr[k][j + 1] = temp;

				}
			}

		}
	}

	/*//��������
	for (i = 0; i < n - 1; i++)
	{
		if (i % 2 == 0)  //¦�����϶� 0�� 2�� 4�� ����
		{
			for (j = 0; j < (n - i) - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;

				}
			}
		}
	}

	//��������
	for (i = 0; i < n - 1; i++)
	{
		if (i % 2 == 1) // Ȧ�����϶� 1�� 3�� 5�� ����
		{
			for (j = 0; j < (n - i) - 1; j++)
			{
				if (arr[j] < arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;

				}
			}
		}
	}*/
}