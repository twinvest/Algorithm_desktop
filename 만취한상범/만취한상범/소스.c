#include<stdio.h>
int main(void)
{
	int flag=0; //탈출수
	int i = 0; //케이스
	int n = 0; //방의 개수.         0은 열린거. 1은 닫힌거.
	int arr[101] = { 0 };
	scanf("%d", &i); //케이스
	

	
	while (i--) //i는 케이스임.
	{

		scanf("%d", &n); //방개수
		for (int j = 1; j <= n; j++) //라운드
		{
			for (int z = 1; z <= n; z++)//방설정
			{
				if (arr[z*j] == 0)
					arr[z*j] = 1;
				else
					arr[z*j] = 0;
			}
		}

		for (int j = 1; j <= n; j++)
		{
			if (arr[j] == 1)
				arr[j] = 0;
				++flag;
		}
		printf("%d\n", flag);


	}

	return 0;
}