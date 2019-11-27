#include<stdio.h>
int main()
{
	/*int * pi = (int*)malloc(sizeof(int) * 5);
	
	for (int i = 0; i < 4; i++)
	{
		pi[i] = i;
		printf("pi[%d]에 저장된 값 : %d\n", i, pi[i]);
	}
	
	*pi = 1;
	printf("%d", *pi);*/

	double * p = (double*)malloc(sizeof(double));
	*p = 2.54;
	printf("%lf", *p);

}