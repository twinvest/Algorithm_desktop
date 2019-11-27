#include<stdio.h>

int main()
{
	int arr[] = { 5,3,2,4,1 };
	int i, j;
	int size = sizeof(arr) / sizeof(int);
	int insData;

	for (i = 1; i < size; i++) //i가 1로 시작!! 첫번째 인덱스(0)는 이미 정렬되어있다고 생각해도됨.
	{
		insData = arr[i];

		for (j = i - 1; j >= 0; j--) //자리를 찾아갈때 반복을 담당하는 부분.
		{
			if (arr[j] > insData) //비교하고
				arr[j + 1] = arr[j]; // 이동하고
			else
				break;
		}

		arr[j + 1] = insData;
	
	}
	for (i = 0; i < 5; i++)
		printf("%d", arr[i]);

	printf("\n");
	return 0;

}