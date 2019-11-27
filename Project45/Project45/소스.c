#include<stdio.h>
int main()
{
	int t = 0;
	int test_case;
	scanf("%d", &test_case);

	int * final = (int*)malloc(sizeof(int)*test_case);

	for (int i = 0; i < test_case; i++)
	{
		int arr[50] = { 0, }; //색깔저장.
		int color = 0;
		int sum = 0;
		int sum1 = 0;
		int result = 0; //p1의 가중치 까지 더한 합. 즉, p2의 순차합과 비교할 것.
		
		int car_num;
		int car_color;
		

		scanf("%d", &car_num);
		scanf("%d", &car_color);
		int * p1 = (int*)malloc(sizeof(int)*car_color);
		int * p2 = (int*)malloc(sizeof(int)*car_num);
		
		
		for (int j = 0; j < car_color; j++)  //죄수차량 색깔 입력받기.
		{
			scanf("%d", &p1[j]);
		}
		for (int k = 0; k < car_num; k++) //차량개수 입력받기.
		{
			scanf("%d", &p2[k]);
		}


		for (int j = 0; j < car_color; j++)  //sum(4)과 result(12)를 구하기.
		{
			sum = sum + p1[j];               //sum 구하기
			if (p1[j] != 0) 
			{                //result 구하기
				result = result + ((j + 1)*p1[j]);
				arr[color] = p1[j];
			}
			color++;

		}
		/*for (int i = 0; i < 50; i++)
			printf("%d ", arr[i]);*/


		for(int k=0; k<car_num-sum+1; k++) //조건1. 4(sum)개씩 검색을 한다.
		{
			sum1 = 0;
			for (int i = k; i < sum+k; i++)  //4개씩 검색하는 것의 합을 구하고
			{
				sum1 = sum1 + p2[i];        
				if (sum1 == result) //조건2. 그 합이 만약 result와 일치하면 조건검사 ㄱㄱ
				{
					int a = investigate(p2, arr, k, sum);
					if (a == 50)
						final[t++] = k + 1;
					else
						final[t++] = 0;
				}

			}
		}
	}
	for (int t = 0; t<test_case; t++)
		printf("#%d %d\n", t + 1, final[t]);
	
}
int investigate(int * p2, int *p, int k, int sum)//조건3, 4 종류가 일치할 것.
{
	int last = k + sum;
	int flag = 0;
	int arr2[50] = {0, };
	for (k; k<last; k++)
	{
		arr2[(p2[k]-1)]++;
	}
	for (int i = 0; i < 50; i++)
	{
		if ((p[i] == arr2[i]) && *p!=NULL)
			flag++;
	}

	return flag;
	
}