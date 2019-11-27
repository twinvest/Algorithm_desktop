#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Wallet {
	
	int numofmonsterball;
	int numofpotion;

}Wallet;

typedef struct Pokemon {


	char name[20];
	char nick[20];
	char type[20];
	int  agress;
	int  hp;


} Pokemon;


Pokemon* init(Pokemon*real, Pokemon*arr, int poketnum) {

		
	/*char *name[] = { "리자드", "이상해풀", "이상해씨", "피카츄", "라이츄", "푸린", "잠만보", "이브이" };
	char *type[] = { "풀타입", "물타입", "불타입", "복학생타입", "못생긴타입" };
	char *nick[] = { "잉", "앙", "복치", "톨끼" };
	printf("이름을 입력하세요");
	scanf("%s", pokemon->name);
	printf("타입을 입력하세요");
	scanf("%s", pokemon->type);
	printf("별명을 입력하세요");
	scanf("%s", pokemon->nick);*/
	strcpy(real->name, arr[rand() % poketnum].name);
	strcpy(real->type, arr[rand() % poketnum].type);
	//strcpy(real->nick, nick[rand() % 4]);

	(real->agress) = rand() % 201;
	(real->hp) = rand() % 1201;

	return real;


	//printf("%s %s %d %d", arr[rand() % poketnum].name, arr[rand() % poketnum].type, arr[rand() % poketnum].agress, arr[rand() % poketnum].hp);

}


typedef struct mymonster {

	char name[20];
	char nick[20];
	char type[20];
	int agress;
	int hp;


} Mymonster;


void print_mymonster(Mymonster*my)
{

	printf("당신이 선택한 포켓몬의 정보입니다.\n");
	printf("%s", my->name);
	printf("%d", my->hp);
	printf("%d", my->agress);

}


void init_mymonster(Mymonster*my, int num)
{
	char *name[] = { "파이리", "이상해씨", "꼬부기" };
	char *nick[] = {"파이터", "톨끼", "개복치"};
	char *type[] = {"불속성", "풀속성", "물속성"};



	if (num == 1)
	{
		strcpy(my->name, name[0]);
		strcpy(my->type, type[0]);
		strcpy(my->nick, nick[0]);
		//my->name = { "파이리" };
		//my->nick = { "파이터" };
		//my->type = { "불속성" };
		my->agress = rand() % 51 + 100;
		my->hp = rand() % 501 + 500;
		print_mymonster(my);
	}
	else if (num == 2)
	{
		strcpy(my->name, name[1]);
		strcpy(my->type, type[1]);
		strcpy(my->nick, nick[1]);
		/*my->name = "이상해씨";
		my->nick = "도도남";
		my->type = "풀속성";*/
		my->agress = rand() % 51 + 100;
		my->hp = rand() % 501 + 500;
		print_mymonster(my);
	}

	else if (num == 3)
	{
		strcpy(my->name, name[2]);
		strcpy(my->type, type[2]);
		strcpy(my->nick, nick[2]);
		/*my->name = "꼬부기";
		my->nick = "귀요미";
		my->type = "물속성";*/
		my->agress = rand() % 51 + 100;
		my->hp = rand() % 501 + 500;
		print_mymonster(my);
	}
	
	else
		return;
}



void choice_mymonster(Mymonster*my, int num)
{
	switch (num)
	{
	case 1:
		printf("파이리를 선택했습니다.\n");
		Mymonster * fire =my; //= (Mymonster*)malloc(sizeof(Mymonster));
		init_mymonster(fire, num);


	case 2:
		printf("이상해씨를 선택했습니다.\n");
		Mymonster * flower=my; //= (Mymonster*)malloc(sizeof(Mymonster));
		init_mymonster(flower, num);


	case 3:
		printf("꼬부기를 선택했습니다.\n");
		Mymonster * water=my; //= (Mymonster*)malloc(sizeof(Mymonster));
		init_mymonster(water, num);
	}
}

int boolean_type(Pokemon*real, Mymonster*my)
{
	int equal;                                         //0반환시 둘이 같은 속성 , 1반환시 내가 약한속성, 2반환시 내가 강한속성
	int me;
	int you;

	char *type[] = { "풀타입", "물타입", "불타입" };
	char arr1[20] = { my->type };
	char arr2[20] = { real->type };

	equal = strcmp(my->type, real->type);

	if (equal == 0)
	{
		printf("적과 나는 동일한 타입입니다.");
		return equal;
	}

	for (int i = 0; i < 3; i++)
	{
		strcmp(type[i], my->type);
		if (strcmp == 0)
		{
			me = i+1;
			break;
		}

	}

	for (int i = 0; i < 3; i++)
	{
		strcmp(type[i], real->type);
		if (strcmp == 0)
		{
			you = i+1;
			break;
		}

	}

	if (me % 3<you)
	{
		printf("상대가 강한속성입니다.");
		return 1;
	}

	else
	{
		printf("내가 강한 속성입니다.");
		return 2;
	}



	/*strcpy(real->name, arr[rand() % poketnum].name);



	
	equal = strcmp(my->type, real->type);
	
	if (equal == 0)
	{
		printf("적과 나는 동일한 타입입니다.");
		return equal;
	}

	else
	{

		for (int i = 0; i < 3; i++)
		{
			differ = strcmp(type[i], my->type);
			if (differ == 0)
			{
				if (i % 3 < (i + 1) % 3)
					printf("내가 더 쎈속성이다.");

				else

				
			}





		}


	}*/


}

void monster_war(int type_priority, Pokemon*real, Mymonster*my, Mymonster**mylist, int*p)
{
	int num; //계속 싸울건지 포기할건지.
	int poket_number; //포켓못 꺼낼때 몇번째 포켓몬꺼낼지 입력받는 변수.

	printf("곧 전쟁이 시작됩니다...\n");
	Sleep(1000);
	printf("3...\n");
	Sleep(1000);
	printf("2..\n");
	Sleep(1000);
	printf("1..전쟁!\n");


	if (type_priority == 0)
	{
		do
		{
			printf("같은 속성이군 내가 먼저 공격한다ㅋ이얍!!!!\n\n\n");
			Sleep(2000);
			printf("내 공격을 맞고 상대가 절절빕니다. 상대의 체력이 %d만큼 감소했습니다.\n\n", my->agress*0.5);
			real->hp = (real->hp) - (my->agress*0.5);

			printf("상대가 공격해온다 가소롭군!!ㅋ\n\n");
			Sleep(2000);
			printf("상대의 공격을 맞고 내 체력이 %d만큼 감소했습니다.", real->agress*0.5);
			my->hp = (my->hp) - (real->agress*0.5);

		} while (my->hp >= 0 && real->hp >= 0);
		
		if (my->hp <= 0)
		{
			printf("전쟁에서 패배했습니다...\n");
			printf("계속 싸우시겠습니까?? 1. 계속 싸운다 2. 포기한다.\n");
			scanf("%d", &num);

			if (num == 1)
			{
				//내가 보관중인 포켓몬 끄내오는 함수.
				int a = display_mypoketmon(mylist, p);

				if (a == 1)
					printf("더이상 꺼내올 몬스터가 없어 눈앞이 깜깜해졌다....");
				
				if (a == 2)
				{
					int c;
					printf("몇번째 포켓몬을 꺼내시겠습니까?");
					scanf("%d", &c);
					my = mypoketmonlist_call(mylist, p, c);
				}


			}
			else if (num == 2)
			{
				printf("전쟁을 종료합니다.\n");
				return;
			}

			else
				printf("1 또는 2 둘중에 하나를 고르세요.");

		}
		
		if (real->hp <= 0)
		{
			if (real->hp == 0)
				printf("포켓몬이 죽지 않고 튀어버렸다...\n");

			printf("전쟁에서 승리했습니다!!!\n\n");
			return;
		}

	}


	if (type_priority == 1)
	{
		do
		{
			printf("내가 약한속성이라 상대가 먼저 공격해온다...ㅈㄴ아프다...\n\n\n");
			Sleep(2000);
			printf("공격을 맞고 체력이 %d만큼 감소됐습니다.\n\n", real->agress*1.5);
			my->hp = (my->hp) - (real->agress*1.5);

			printf("내 차례다 이얍!!! 공격엉~~\n\n\n");
			Sleep(2000);
			printf("상대가 나의 공격을 맞고 체력이 %d만큼 감소됐습니다.\n\n", my->agress);
			real->hp = (real->hp) - (my->agress);
			
		} while (my->hp >= 0 && real->hp >= 0);
		
		if (my->hp <= 0)
		{
			printf("전쟁에서 패배했습니다...\n");
			printf("계속 싸우시겠습니까?? 1. 계속 싸운다 2. 포기한다.\n");
			scanf("%d", &num);

			if (num == 1)
			{
				//내가 보관중인 포켓몬 끄내오는 함수.
				display_mypoketmon(mylist, p);
			}
			if (num == 2)
			{
				printf("전쟁을 종료합니다.\n");
				return;
			}

		}

		if (real->hp <= 0)
		{
			if (real->hp == 0)
				printf("포켓몬이 죽지 않고 튀어버렸다...\n");

			printf("전쟁에서 승리했습니다!!!\n\n");
			return;
		}
	}

	
	if (type_priority == 2)
	{
		do
		{
			printf("내가 강한속성이라 먼저 공격한다!!이얍!!!!\n\n\n");
			Sleep(2000);
			printf("내 공격을 맞고 상대가 절절빕니다. 상대의 체력이 %d만큼 감소했습니다.\n\n", my->agress*1.5);
			real->hp = (real->hp) - (my->agress*1.5);

			printf("상대가 공격해온다 가소롭군!!ㅋ\n\n");
			Sleep(2000);
			printf("상대의 공격을 맞고 내 체력이 %d만큼 감소했습니다.", real->agress);
			my->hp = (my->hp) - (real->agress);

		} while (my->hp >= 0 && real->hp >= 0);

		if (my->hp <= 0)
		{
			printf("전쟁에서 패배했습니다...\n");
			printf("계속 싸우시겠습니까?? 1. 계속 싸운다 2. 포기한다.\n");
			scanf("%d", &num);

			if (num == 1)
			{
				display_mypoketmon(mylist, p);
			}
			if (num == 2)
			{
				printf("전쟁을 종료합니다.\n");
				return;
			}

		}

		if (real->hp <= 0)
		{
			if (real->hp == 0)
				printf("포켓몬이 죽지 않고 튀어버렸다...\n");
			
			printf("전쟁에서 승리했습니다!!!\n\n");
			return;
		}
	}


}




void travel_mymonster(Mymonster**mylist, Pokemon*arr, int poketnum, Pokemon*real, Mymonster*my ,int*p)
{
	int num;                       //메뉴 1. 공격 2. 도망 3. 가방열기
	int type_priority;             //0반환시 둘이 같은 속성 , 1반환시 내가 약한속성, 2반환시 내가 강한속성
	printf("길을걷는중....\n");
	
	Sleep(1000);
	printf("3...\n");
	Sleep(1000);
	printf("2...\n");
	Sleep(1000);
	printf("1...\n");

	printf("적이 발견됐다!!!\n");

	printf("1. 공격\t 2.도망치기\t 3. 가방열기");
	scanf("%d", &num);
	fflush(stdin);

	if (num == 1)
	{

		real = init(real, arr, poketnum);

		printf("\n---------------------------\n");
		printf("적의 정보 \n ");
		printf("이름 : %s \n", real->name);
		printf("공격력 : %d \n", real->agress);
		printf("체력 : %d \n", real->hp);
		printf("타입 : %s \n", real->type);
		printf("\n---------------------------\n");

		type_priority=boolean_type(real, my);
		
		monster_war(type_priority, real, my, mylist, p);
	
	
	
	
	}


	
	//printf("%s %s %d %d", arr[rand()%poketnum].name, arr[rand() % poketnum].type, arr[rand() % poketnum].agress, arr[rand() % poketnum].hp);
	


}

void goto_store(int*p, Wallet*pointer)
{
	int item; //물약 몬스터볼
	int num; //개수
		

	printf("1.몬스터볼은 1000원 \n");
	printf("2.회복물약은 2500원 \n");

	printf("구입하려는 아이템의 번호를 입력하세요 : ");
	scanf("%d", &item);

	if (item == 0)
	{
		printf("상점을 빠져나갑니다.");
		return;
	}


	else if (item == 1)
	{
		printf("몬스터볼을 몇개 구매하시겠습니까?");
		scanf("%d", &num);
		fflush(stdin);

		if (*p < 1000 * num)
		{
			printf("돈이 부족하여 살 수가 없습니다.");
		}

		else
		{
			printf("몬스터 %d개가 성공적으로 구매됐습니다.", num);
			*p = *p - 1000 * num;

			for (int i = 0; i < num; i++)
				pointer->numofmonsterball++; //구조체 ++어떻게 할꺼~
		}
	}

	else if (item == 2)
	{
		printf("포션을 몇개 구매하시겠습니까?");
		scanf("%d", &num);
		fflush(stdin);

		if (*p < 2500 * num)
		{
			printf("돈이 부족하여 살 수가 없습니다.");
		}

		else
		{
			printf("포션 %d개가 성공적으로 구매됐습니다.", num);
			*p = *p - 2500 * num;

			for (int i = 0; i < num; i++)
				pointer->numofpotion++;
		}
	}

	else
		return;

	
}

Mymonster* mypoketmonlist_call(Mymonster**mylist, int*p_position, int a)
{
		
	Mymonster*newpoketmon = mylist[a-1];


	for (int i=0; i<=*p_position; i++)
	{
		mylist[a - 1] = mylist[a];
	}
	
	*p_position--;

	return newpoketmon;
}

void mypoketmonlist_insert(Mymonster**mylist, Mymonster*my, int*p_position)
{
	*p_position++;


	mylist[*p_position] = &my;
	
}

int display_mypoketmon(Mymonster**mylist, int*p)
{
	if (*p == -1)
	{
		printf("꺼낼 포켓몬이 없습니다.");
		return 1;
	}

	else
	{

		for (int i = 0; i < *p; i++)
		{
			printf("%d번째 포켓몬의 이름 : %s\n", i + 1, mylist[i]->name);
			printf("%s\n", mylist[i]->type);
			printf("%d\n", mylist[i]->hp);
			printf("%d\n", mylist[i]->agress);

		}

		return 2;
	}
}


int main(void) {


	int position = -1; // 내가 포켓몬 추가할때마다 증가. 
	
	
	Wallet mywallet = {0, 0};
	int owned_money=10000;
	int*p = &owned_money;                                                                            //여기까지 지갑관련

	FILE*fp = (FILE*)fopen("poketmon_list.txt", "rt");
	Pokemon*arr;
	int i, poketnum;

	fscanf(fp, "%d", &poketnum);

	arr = (Pokemon*)malloc(sizeof(Pokemon)*poketnum);

	for (i = 1; i <= poketnum; i++)
	{
		fscanf(fp, "%s %s %d %d", arr[i-1].name, arr[i-1].type, arr[i-1].agress, arr[i-1].hp );
	}                                                                                                              //여기까지 적으로 나타날 리스트 배열에 때려 밖음.


	Mymonster mylist[6];                                                                                        //내가 가진 포켓몬.
	
	Mymonster my;                                                                                                  //내 케릭터 구조체.
	
	
	
	Pokemon real;                                                                                                 //적 구조체.

	mypoketmonlist_insert(mylist, &my, &position);
	
	int num;//어떤 포켓몬을 고를지
	int num2;//여행을 떠날지 말지 상점갈지

	
	printf("=============");
	printf("  포켓몬스터  ");
	printf("press enter key");
	printf("=============");
	getchar();

	printf("당신의 포멧몬을 골라주세요.");
	printf("1. 파이리 2. 이상해씨 3. 꼬부기");
	scanf("%d", &num);

	choice_mymonster(&my, num);


	while (1)
	{
		printf("여행을 떠나시겠습니까??");
		printf("1. 네  2. 아니오  3. 상점가기");
		scanf("%d", &num2);
		fflush(stdin);

		//여행을 떠날지 말지 상점갈지

		if (num2 == 1)
			travel_mymonster(mylist, arr, poketnum, &real, &my, &position);
	    else if (num2 == 2)
		{
			printf("게임을 저장하시겠습니까?");

		}

		else if (num2 == 3)
		{
			printf("현재 소유 금액 : %d\n", owned_money);
			goto_store(p, &mywallet);
		}

		else
			printf("옳바른 숫자를 입력해주세요.");

	}
	return 0;
		
}
