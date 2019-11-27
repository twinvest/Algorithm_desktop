#include<stdio.h>
int main()
{
	int num;
	int arr1[1000] = { 0, };  //입력 받은 배열.
	int arr2[1000] = { 0, }; //진짜 구하려는 답.
	int * p1 = arr1;
	int * p2 = arr2;

	while (1) //수열의 길이
	{
		scanf("%d", &num);
		if (num >= 1 && num <= 1000)
			break;
	}
	for (int i = 0; i < num; i++) //수열 입력.
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