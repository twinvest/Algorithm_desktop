#include<string.h>
#include<stdio.h>

int main()
{
	char s[] = "a joy that's shared is a joy made double";
	char sub[] = "joy";

	char*p;
	int location = 0;
	
	
	p = strstr(s, sub);
	location = (int)(p - s);
	if (p != NULL)
		printf("ù��° %s�� %d���� �߰ߵǾ���\n", sub, location);
	else
		printf("%s�� �߰ߵ��� �ʾ���.", sub);
}