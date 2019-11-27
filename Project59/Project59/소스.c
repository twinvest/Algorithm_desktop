#include<stdio.h>
int solution(int N, int* s)
{
	int best_customer=0;
	int i; //상품개수
	int sum = 0;
	for (i = 0; 0<=s[i]&&s[i]<=100 &&i<100; i++)
		sum += s[i];

	i = i - 1;
	int sum2 = i * N;
	
	while (sum > sum2)
	{
			sum2++;
			best_customer++;
	}
	return best_customer;
}

int main()
{
	int s[] = {9,9,9,9,9};
	int N=10; //사람 수
	int a = solution(N, s);
	printf("%d", a);
}