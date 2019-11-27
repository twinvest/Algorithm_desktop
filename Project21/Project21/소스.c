#include<stdio.h>

#define NAME           "김태우"
#define AGE            26
#define PRINT_ADDR     puts("주소 : 경기도 안산시\n")

int main(void)
{
	printf("이름 : %s \n", NAME);
	printf("나이 : %s \n", AGE);
	PRINT_ADDR;
	return 0;
}
