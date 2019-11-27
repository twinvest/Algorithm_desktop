#include<stdio.h>
int main()
{
	int num;
	int arr1[1000] = { 0, };  //입력 받은 배열.
	int arr2[1000] = { 0, }; //진짜 구하려는 답.
	
	

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

			printf("%d번째바퀴 때 diff와 same의 값 : %d %d\n", i, diff, same);
		}

	}



}