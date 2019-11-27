#include <stdio.h>
int main(int argc, const char * argv[])
{
	char a[200];
	while (scanf("%[^\n]s", a) != -1)
	{
		getchar();
		printf("%s\n", a);
	}
}
