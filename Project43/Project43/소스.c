#include<stdio.h>
int main()
{
	int num;
	int arr1[1000] = { 0, };  //�Է� ���� �迭.
	int arr2[1000] = { 0, }; //��¥ ���Ϸ��� ��.
	
	

	while (1) //������ ����
	{
		scanf("%d", &num);
		if (num >= 1 && num <= 1000)
			break;
	}
	for (int i = 0; i < num; i++) //���� �Է�.
	{
		scanf("%d", &arr1[i]);
	}

	int diff = 0;
	int same = 0;
	for (int i = 0; i < num; i++)
	{
		diff = 0;
		same = 0;
		for (int j = 0; j < num; j++)
		{
			if (arr1[i] != arr2[j])
			{
				arr2[i] = arr1[i];
				++diff;
			}
			else
				++same;

			printf("%d��°���� �� diff�� same�� �� : %d %d\n", i, diff, same);
		}

	}



}