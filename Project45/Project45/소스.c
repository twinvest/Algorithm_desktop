#include<stdio.h>
int main()
{
	int t = 0;
	int test_case;
	scanf("%d", &test_case);

	int * final = (int*)malloc(sizeof(int)*test_case);

	for (int i = 0; i < test_case; i++)
	{
		int arr[50] = { 0, }; //��������.
		int color = 0;
		int sum = 0;
		int sum1 = 0;
		int result = 0; //p1�� ����ġ ���� ���� ��. ��, p2�� �����հ� ���� ��.
		
		int car_num;
		int car_color;
		

		scanf("%d", &car_num);
		scanf("%d", &car_color);
		int * p1 = (int*)malloc(sizeof(int)*car_color);
		int * p2 = (int*)malloc(sizeof(int)*car_num);
		
		
		for (int j = 0; j < car_color; j++)  //�˼����� ���� �Է¹ޱ�.
		{
			scanf("%d", &p1[j]);
		}
		for (int k = 0; k < car_num; k++) //�������� �Է¹ޱ�.
		{
			scanf("%d", &p2[k]);
		}


		for (int j = 0; j < car_color; j++)  //sum(4)�� result(12)�� ���ϱ�.
		{
			sum = sum + p1[j];               //sum ���ϱ�
			if (p1[j] != 0) 
			{                //result ���ϱ�
				result = result + ((j + 1)*p1[j]);
				arr[color] = p1[j];
			}
			color++;

		}
		/*for (int i = 0; i < 50; i++)
			printf("%d ", arr[i]);*/


		for(int k=0; k<car_num-sum+1; k++) //����1. 4(sum)���� �˻��� �Ѵ�.
		{
			sum1 = 0;
			for (int i = k; i < sum+k; i++)  //4���� �˻��ϴ� ���� ���� ���ϰ�
			{
				sum1 = sum1 + p2[i];        
				if (sum1 == result) //����2. �� ���� ���� result�� ��ġ�ϸ� ���ǰ˻� ����
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
int investigate(int * p2, int *p, int k, int sum)//����3, 4 ������ ��ġ�� ��.
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