#include<stdio.h>
int main()
{
	int n = 0;
	double s = 0;
	double arr[100] = { 0, };
	int number;
	scanf("%d", number);

	while (number > s)
	{
		++n;
		s = (0.5*n*n) + (0.5*n);
		arr[n] = s;
	}
}