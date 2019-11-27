#include <stdio.h>
#include <stdlib.h> //�����Լ� ȣ��

void Swap(int arr[], int a, int b) // a,b ���� �Լ� 
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
int Partition(int arr[], int left, int right)
{
	int pivot = arr[left]; // �ǹ��� ��ġ�� ���� ���ʿ��� ����
	int low = left + 1;
	int high = right;

	while (low <= high) // �����Ǳ� ������ �ݺ��Ѵ� 
	{
		while (pivot >= arr[low] && low <= right) // �ǹ����� ū ���� ã�� ���� 
		{
			low++; // low�� ���������� �̵� 
		}
		while (pivot <= arr[high] && high >= (left + 1)) // �ǹ����� ���� ���� ã�� ���� 
		{
			high--; // high�� �������� �̵�
		}
		if (low <= high)// �������� ���� �����̸� ���� ���� ���� 
		{
			Swap(arr, low, high); //low�� high�� ���� 
		}
	}
	Swap(arr, left, high); // �ǹ��� high�� ����Ű�� ����� ��ȯ 
	return high;  // �Ű��� �ǹ��� ��ġ������ ��ȯ 

}


void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right); // �ѷ� �����
		QuickSort(arr, left, pivot - 1); // ���� ������ �����Ѵ�.
		QuickSort(arr, pivot + 1, right); // ������ ������ �����Ѵ�.
	}
}

//�����Լ�
int main()
{
	int n, i;
	int arr[100];


	printf("��� ���ڷ� �����Ͻðڽ��ϱ�?\n");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		arr[i] = rand() % 1000;

	printf("������ �迭 :");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	QuickSort(arr, 0, n - 1);

	printf("������ �迭 :");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}