//������ ���� ����
#include<stdio.h>
void swap(int*p1, int*p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
int main(void)
{
	/*char * pc;
	int * pi;
	double * pd;

	pc = (char*)10000;
	pi = (int*)10000;
	pd = (double*)10000;
	printf("������ : %p %p %p\n", pc, pi, pd);

	pc++;
	pi++;
	pd++;
	printf("������ : %p %p %p\n", pc, pi, pd);

	return 0;*/

	/*int a = 10;
	int b = 20;
	printf("������ : %d %d\n", a, b);

	swap(&a, &b);

	printf("������ : %d %d\n", a, b);*/

	/*int a[] = { 1,2,3,4,5,6 };
	int * p = a;
	int * q = a+3;

	printf("%d\n", *(a+1));
	printf("%d\n", *(p+2));
	printf("%d\n", *(q+3));*/

	/*char str1[6] = "seoul";
	char str2[] = { 'i','s','\0' };
	char str3[] = "the capital city of korea.";
	printf("%s %s %s\n", str1, str2, str3);*/

	/*char str[] = "aaaaa";
	int i = 0;
	while (str[i] != '\0')
		++i;
	printf("�ݺ������� ���� %s �� ���̴� %d\n", str, i);

	int a=strlen(str);
	printf("strlen���� ���� ���̴� %d\n", a);*/

	int ch;
	ch = getch();
	putch(ch);

	char s[11] = "hello";
	char t[10] = "world";
	strcat(s, t);
	printf("%s \n",s);
}