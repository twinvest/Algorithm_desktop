#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int meme(void);
int comcom(void);
int win(int a, int b);


int main(void)
{
	int com, me;
	int result;
	int num;
	srand((int)time(NULL));

	
	START:
	me = meme();
	com = comcom();

	win(com, me);
	
	printf("������ ����Ͻðڽ��ϱ�? 1.yes 2. no");
	scanf("%d", &num);

	if (num == 1)
	goto START;
	
	return 0;
}

int comcom(void)
{
	int sel = rand() % 3 + 1;
	
	if (sel == 1)
		printf("��ǻ�� ����\n");
	
	else if (sel == 2)
		printf("��ǻ�� ����\n");
	
	else
		printf("��ǻ�� ��\n");
	
	return sel;
}

int meme(void)
{
	int sel;
	printf("�����ض�~~ ����1 ����2 ��3 ��ǻ�ʹ� �̰ܾ���~");
	scanf("%d", &sel);
	
	if (sel == 1)
		printf("���� ����\n");
	else if (sel == 2)
		printf("���� ����\n");
	else
		printf("���� ��\n");

	return sel;
}

int win(int a, int b)
{
	if (a == b)
		printf("�����ϴ�.\n");
	else if (a % 3 == (b + 1) % 3)
		printf("�����̰��!!!\n");
	else
		printf("��������...\n");


}
