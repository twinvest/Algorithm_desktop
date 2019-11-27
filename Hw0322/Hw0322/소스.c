#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void BubbleSort(int arr[], int n);

int main()
{

	int num;
	int i, j;
	int arr[100][100]; // 배열선언

	
	
	printf("정렬할 배열의 size를 입력하세요");
	scanf_s("%d", &num);
	printf("%d x %d의 배열을 정렬중입니다.\n", num, num);

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			arr[i][j] = rand();   //난수로 배열 전부 채워넣음. num까지만 채워넣음.
		}
	}

	BubbleSort(arr, num);  //밑에정의한 버블정렬로 정렬시작.

	for (i = 0; i < num; i++)  //정렬된 배열 출력 for문
	{
		for (j = 0; j < num; j++)
		{
			printf("%d   ", arr[i][j]);
		}
		printf("\n");
	}



	return 0;

}

void BubbleSort(int arr[][100], int n) //n은 num이 되어야함.
{
	int i, j, k;
	int temp;

	//오름차순

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

	/*//오름차순
	for (i = 0; i < n - 1; i++)
	{
		if (i % 2 == 0)  //짝수행일때 0행 2행 4행 정렬
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

	//내림차순
	for (i = 0; i < n - 1; i++)
	{
		if (i % 2 == 1) // 홀수행일때 1행 3행 5행 정렬
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