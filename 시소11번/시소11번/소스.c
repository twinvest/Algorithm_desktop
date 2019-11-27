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
		printf("첫번째 %s가 %d에서 발견되었음\n", sub, location);
	else
		printf("%s가 발견되지 않았음.", sub);
}