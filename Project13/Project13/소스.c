#include<stdio.h>

int main()
{
	int num;
	int arr[100];
	int*ar1 = arr + 99;

	printf("2진수로 변환할 10진수의 값을 입력해보세요 : ");
	scanf_s("%d", &num);


	for (int i = 0; i < 100; i++)
	{
		arr[i] = 0;
	}


	for (int i = 0; ; i++)
	{

		if (num == 1)// 여기부터
		{
			arr[i] = 1;
			break;
		}
		if (num / 2 == 1)
		{
			if (num % 2 == 0)
			{
				arr[i] = 0;
				arr[i + 1] = 1;
			}
			else {
				arr[i] = 1;
				arr[i + 1] = 1;
			}
			break;
		}// 여기까지 위로뺐음 왜냐? 2번계산하면 안되니까
		if (num % 2 == 0)
		{
			arr[i] = 0;
			num = num / 2;
		}

		else if (num % 2 != 0)
		{
			arr[i] = 1;
			num = num / 2;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		printf("%d", *ar1);
		ar1--;
	}

	return 0;


}