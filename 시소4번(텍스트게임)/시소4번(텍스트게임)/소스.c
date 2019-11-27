#include<stdio.h>
#include<windows.h>

void start(void)
{
	Sleep(1000);
	printf("3...\n");
	Sleep(1000);
	printf("2...\n");
	Sleep(1000);
	printf("1...\n");
	Sleep(1000);
	printf("game start!!\n");
}

int selectcall(void)
{
	int selection;
	printf("======================\n");
	printf("1.Fight the villain\n");
	printf("2.Save the citizen\n");
	printf("3.Return to secret base\n");
	printf("======================\n");
	printf("무엇을 선택하시겠습니까? : ");
	scanf("%d", &selection);
	
	switch (selection)
	{
	case 1:
		printf("You win!\n");
		return 1;

	case 2:
		printf("You saved the citizen!\n");
		return 2;

	case 3:
		printf("who will save the world?\n");
		return 3;

	default:
		printf("잘못입력했습니다!\n");
		break;
	}
}


int main()
{
	start();
	int selection;
	while (1)
	{
		selection = selectcall();
		if (selection == 3)
			break;
	}
	return 0;
	
}