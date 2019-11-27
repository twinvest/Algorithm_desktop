#include<cstdio>
#include<iostream>
int main()
{
	int A, B;
	while(1)
	{
		scanf("%d", &A);
		scanf("%d", &B);
		if ((A <= 10000 && A >= -10000) && (B <= 10000 && B >= -10000))
			break;
	}
	
	
	if (A > B)
		printf(">");
	if (A < B)
		printf("<");
	if (A == B)
		printf("==");
}