#include<stdio.h>
int main()
{
	char a[100] = { 0 };

	int i = 0;
	printf("문자열 입력 : ");
	scanf("%s", a);


	for (i = 0; a[i] != '\0'; i++)
	{
		if ('a' <= a[i] && a[i] <= 'z')
		{
			a[i] = a[i] - 32;
		}
		else if ('A' <= a[i] && a[i] <= 'z')
		{
			a[i] = a[i] + 32;
		}

		else
		{
			a[i] = a[i];
		}
	}

	printf("%s", a);

	return 0;
}