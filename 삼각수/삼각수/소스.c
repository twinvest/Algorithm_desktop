#include<stdio.h>

int main()
{
	int flag=0;
	int n=0;
	double number=0;
	double s=0;
	double arr[100];

	while (number<3 || 10000<number) //입력조건
	{
		scanf("%lf", &number);
	}
	
	while (number > s) //n구하기.
	{
		++n;
		s = (0.5*n*n) + (0.5*n);
		arr[n] = s;
	}
	if (arr[n] > number) //입력받은 수 보다 작으면서 입력받은 수에 제일 가까운 삼각수
		--n;
	
	double remainder = number - arr[n]; //입력받은 수와 삼각수를 뺌.
	

	for (int i = 1; i <= n; i++)
	{
		if (remainder == arr[i] || number==6)  //만약 같은게 있다면 무조건 2개로 표현 가능.
		{
			++flag;
		}
	}

	if (flag)
	{
		printf("2개로 표현 가능.\n");
	}
	else
	{
		printf("3개로 표현 가능\n");
	}
	/*printf("n의 값 : %d\n", n);
	printf("s의 값 : %lf\n", s);
	printf("number의 값 : %lf\n", number);
	printf("reaminder의 값 : %lf\n", remainder);
	printf("%d", arr[0]);*/
}