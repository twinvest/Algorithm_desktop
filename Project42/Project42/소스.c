#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	printf("À¯Áö´×°ÕÀÌ ±Í¿±´Ù¸é 1À» ÀÔ·ÂÇÏ¼¼¿ä : ");
		scanf("%d", &b);
	char a1[] = "À¯Áö´×°ÕÀÌ ´õ ±Í¿±´Ù!!";
	char a2[] = "ÆØ±Ï °¡½À±â°¡ ´õ ±Í¿±´Ù!";

	if (b > a)
	{
		printf("%s\n", a1);
	}
}