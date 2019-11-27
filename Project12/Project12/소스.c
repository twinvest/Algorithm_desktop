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
	
	printf("계임을 계속하시겠습니까? 1.yes 2. no");
	scanf("%d", &num);

	if (num == 1)
	goto START;
	
	return 0;
}

int comcom(void)
{
	int sel = rand() % 3 + 1;
	
	if (sel == 1)
		printf("컴퓨터 바위\n");
	
	else if (sel == 2)
		printf("컴퓨터 가위\n");
	
	else
		printf("컴퓨터 보\n");
	
	return sel;
}

int meme(void)
{
	int sel;
	printf("선택해라~~ 바위1 가위2 보3 컴퓨터는 이겨야지~");
	scanf("%d", &sel);
	
	if (sel == 1)
		printf("나는 바위\n");
	else if (sel == 2)
		printf("나는 가위\n");
	else
		printf("나는 보\n");

	return sel;
}

int win(int a, int b)
{
	if (a == b)
		printf("비겼습니다.\n");
	else if (a % 3 == (b + 1) % 3)
		printf("내가이겼따!!!\n");
	else
		printf("내가졌다...\n");


}
