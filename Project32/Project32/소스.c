#include<stdio.h>

int main()
{
	int a, b, c, d;
	printf("µ¡¼À1\n»¬¼À2\n°ö¼À3\n³ª´°¼À4\n");
	printf("¾î¶² ¿¬»êÀ» ÇÏ½Ã°Ú½À´Ï±î?");
	scanf("%d", &a);
	printf("µÎ¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä");
	scanf("%d", &b);
	scanf("%d", &c);

	switch (a)
	{
	case 1:
		d = b + c;
		printf(d);
	case 2:
		d = b - c;
		printf(d);
	case 3:
		d = b * c;
		printf(d);
	case 4:
		d = b / c;
		printf(d);
	default:
		break;
	}
}