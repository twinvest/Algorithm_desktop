#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void BubbleSort(int arr[][10], int n);

int main()
{

	int num;
	int i, j;
	int arr[10][10]; // �迭����



	printf("������ �迭�� size�� �Է��ϼ���");
	scanf_s("%d", &num);
	printf("%d x %d�� �迭�� �������Դϴ�.\n", num, num);

	
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			arr[i][j] = rand() % 10;   //������ �迭 ���� ä������. num������ ä������.
		}
	}


	

	BubbleSort(arr, num);  //�ؿ������� �������ķ� ���Ľ���.

	for (i = 0; i < num; i++)  //���ĵ� �迭 ��� for��
	{
		for (j = 0; j < num; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}



	return 0;

}

void BubbleSort(int arr[][10], int n) //n�� num�� �Ǿ����.
{


	int i, j;
	int temp;
	for (i = 0; i < n*n; i++)
	{
		
			for (j = i + 1; j < n*n; j++)
			{
				if (arr[i / n][i%n] > arr[j / n][j%n])
				{
					temp = arr[i / n][i%n];
					arr[i / n][i%n] = arr[j / n][j%n];
					arr[j / n][j%n] = temp;
				}
			}
		
	}


	for (i = 0; i < n*n; i++)
	{
		

			for (j = i + 1; j < n*n; j++)
			{
				if ((i/n) % 2 != 0)
				{

					if (arr[i / n][i%n] < arr[j / n][j%n])
					{
						temp = arr[i / n][i%n];
						arr[i / n][i%n] = arr[j / n][j%n];
						arr[j / n][j%n] = temp;
					}
				}
			}
		
	}


}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*int i, j, k;
	int temp;

	
	int arr1[100];

	for (i = 0; i < 100; i++)
		arr1[i] = rand() % 100;

	for (i = 0; i < n - 1; i++)
	{
		
			for (j = 0; j < (n - 1) - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr1[j] = arr[j + 1];
					arr1[j + 1] = temp;

				}
			}
		
	}*/


	


	

	
	/*//��������

	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n - 1; i++)
		{

			for (j = 0; j < (n - i) - 1; j++)
			{
				if (arr[k][j] > arr[k][j + 1])
				{
					temp = arr[k][j];
					arr[k][j] = arr[k][j + 1];
					arr[k][j + 1] = temp;

				}
			}

		}
	}*/
