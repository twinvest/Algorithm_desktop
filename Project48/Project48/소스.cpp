#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int flag2 = 0;
	int k = 0;
	int number = 0;
	int length=0;
	int result=0;
	
	while (1)                           //수열길이 입력받음.
	{
		scanf("%d", &length);
		if (length <= 1000 && length>=1)
			break;
	}
	
	int * p1 = (int*)malloc(sizeof(int)*length);
	int * p2 = (int*)malloc(sizeof(int)*length);   //똑같은 크기의 수열을 하나 더 만든다.
	
	for (int i = 0; i < length; i++)              //원소 입력받음.
	{
		scanf("%d", &p1[i]);
		if (p1[i] > 1000 && p1[i] < 1)
			break;
		p2[i] = 0;                                //이때 p2는 다 0으로 초기화.
	}
	
	for (int i = 0; i < length; i++)           //중복되지 않는 것들만 일단 순서대로 새로 만든 수열에 집어넣음.
	{
		int flag = 0;
		int pocket=p1[i];
		for (int j = 0; j < length; j++)
		{
			if (pocket == p2[j])
				++flag;
		}
		if (flag == 0)
		{
			p2[number++] = pocket;
		}
	}
	/*for (int i = 0; i < length; i++)
	{
		printf("%d ", p2[i]);
	}
	printf("\n\n");*/
	
	for (int i = 0; i < length; i++)        //위의 중복되지 않는 원소들을 카운팅하고
	{
		if (p2[i] != 0)
			++result;
	}
	//printf("한번 걸래낸 p2의 크기 : %d\n\n", result);
	for (int j=1; j < result; j++)            //뒤에 나와서는 안되는 것들을 카운팅한다. 즉, 오름차순이어야 하는데 더 작은 것들이 나올때 마다 카운팅을 해준다.
	{
		int flag = 0;
		int pocket = p2[j];
		for (int k = j; k >= 0; k--)
		{
			if (pocket < p2[k])
				flag++;
		}
		if (flag != 0)
			flag2++;
	}
	//printf("나와서는 안될 것 : %d\n\n", flag2);

	printf("%d\n", result-flag2);         //그리고 그 둘을 빼준다.
	return 0;
}