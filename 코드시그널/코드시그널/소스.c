#include<stdio.h>
int main()
{
	int num;
	int arr1[1000] = { 0, };  //�Է� ���� �迭.
	int arr2[1000] = { 0, }; //��¥ ���Ϸ��� ��.
	int * p1 = arr1;
	int * p2 = arr2;

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

	int i, j = 0;
	int same = 0;
	int differ = 0;
	int result=0;
	for (i = 0; i < num; i++)
	{
		differ, result = 0;
		for (j = 0; j < num; j++)
		{
			if (arr1[i] != arr2[j])
			{
				differ++;
				break;
			}
			else
			{
				same++;
				break;
			}
			
			
			if (same == 0)
				result++;
		}
	}
	printf("%d\n", result);

	
}