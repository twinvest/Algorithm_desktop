#include<stdio.h>

int main()
{
	int arr[] = { 5,3,2,4,1 };
	int i, j;
	int size = sizeof(arr) / sizeof(int);
	int insData;

	for (i = 1; i < size; i++) //i�� 1�� ����!! ù��° �ε���(0)�� �̹� ���ĵǾ��ִٰ� �����ص���.
	{
		insData = arr[i];

		for (j = i - 1; j >= 0; j--) //�ڸ��� ã�ư��� �ݺ��� ����ϴ� �κ�.
		{
			if (arr[j] > insData) //���ϰ�
				arr[j + 1] = arr[j]; // �̵��ϰ�
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