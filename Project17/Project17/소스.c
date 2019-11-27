#include<stdio.h>
int main()
{
	int num;
	int arr[100];
	int count = 0;

	printf("2진수로 변환할 10진수의 값을 입력해보세요 : ");
	scanf_s("%d", &num);


	for (int i = 0; i < 100; i++)
	{
		arr[i] = 0;
	}


	for (int i = 0; ; i++)
	{

		if (num == 1)// 1일때만 진행, for 바로 탈출
		{
			arr[i] = 1;//마지막 자리에 1대입
			count++;//한자리 추가됬으니 count+1
			break;//1이니 탈출
		}
		if (num / 2 == 1)//2나 3일때 실행
		{
			if (num % 2 == 0)//2일때
			{
				arr[i] = 0;// 마지막 전에 0대입
				arr[i + 1] = 1;//마지막에 1대입
				count += 2;//두자리 추가됬으니 count+2
			}
			else {//3일때
				arr[i] = 1;//마지막전에 1대입
				arr[i + 1] = 1;//마지막에 0대입
				count += 2;//두자리 추가됬으니 count+2
			}
			break;//이 코드들은 배열의 마지막을 결정하니 탈출
		}// 여기까지 위로뺐음 왜냐? 2번계산하면 안되니까
		if (num % 2 == 0)//짝수일때
		{
			arr[i] = 0;//현재 자리에 0대입
			num = num / 2;
			count++;//한자리 추가됬으니 count+1
		}

		else if (num % 2 != 0)
		{
			arr[i] = 1;//현재자리에 1대입
			num = num / 2;
			count++;//한자리 추가됬으니 count+1
		}
	}
	for (int i = count - 1; i >= 0; i--)//2진 자리수의 길이가 count와 같으니 배열의 끝은 arr[count-1]
	{
		printf("%d", arr[i]);
	}
	return 0;
}