#include<stdio.h>
int main()
{
	int month = 0; //월
	float current_money = 0;//원금
	float rate = 0; //이자
	float expense = 0;
	int i = 0;
	
	do {
		printf("원금을 입력하세요 : ");
		scanf("%f", &current_money);
		printf("월이율을 입력하세요 : ");
		scanf("%f", &rate);
		printf("월 지출을 입력하세요 : ");
		scanf("%f", &expense);
		if (expense < (current_money * rate))
			printf("지출보다 이자로 생기는 돈이 더 많으면 돈은 닳지 않습니다. 따라서 무한루프에 빠지니까 다시 입력하세요!\n\n");
			
	} while (expense < (current_money * rate));//무한루프 언제 발생하는가? 빠져나가는 돈(등록금)보다 들어오는 돈(이자)이 높을 때 고갈이 되지 않으니까 무한루프. 
	
	while (1)
	{
		++i;
		current_money = current_money - expense; //등록금이 먼저 빠진다고 가정
		current_money = current_money + (current_money * rate); //그리고 한달후에 이자 발생. 근데 이자가 먼저 발생하고 등록금이 빠져나가면 무한루프임.
		printf("남은 금액 : %lf\n 와일횟수 : %d\n", current_money, i);
		++month;

		if (current_money < 0)
			break;
	}

	printf("%d년 %d달 후에 고갈되었습니다.\n", month / 12, month % 12);
}