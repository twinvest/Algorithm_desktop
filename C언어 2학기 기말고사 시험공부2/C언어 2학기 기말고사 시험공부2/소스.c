#include<stdio.h>
int add(int , int);
int sub(int , int);
int main()
{
	printf("%f\n", 1.23456789);



	/*int a[] = { 10, 20, 30, 40, 50 };//void������ ����
	void* vp;
	
	vp = a;
	*(int*)vp = 35;
	printf("%d\n", a[0]); //��°�� 35*/


	/*int a1, a2; //�Լ�������
	int result, result1, result2;
	a1 = 3;
	a2 = 2;
	int(*pf)(int, int);
	pf = sub;
	result = pf(a1, a2);
	printf("��� �� : %d\n", result);

	int(*p[2])(int, int) = {add, sub}; //�Լ������͹�!! ���̷��� ����� ���ÿ� �ʱ�ȭ�Ұ�!!!
	result1 = p[0](a1, a2);
	result2 = p[1](a1, a2);
	printf("%d %d\n\n", result1, result2);*/
	






	/*char* a[] = { "����", "�λ�", "��õ", "�뱸" };  //���׵� �迭����
	char** x;
	x = a;
	printf("%s\n", *x);*/



	/*char fruits[4][10] = { //�̷��Ծ��� �޸� ����
		"apple",
		"blueberry",
		"orange",
		"melon",
	};

	char* fruits2[] = {"apple", "orange", "ask", "��"};  //�̰� ���׵� �迭����
	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", fruits[i]);
	}
	printf("\n\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", fruits2[i]);
	}*/
	
}

int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}