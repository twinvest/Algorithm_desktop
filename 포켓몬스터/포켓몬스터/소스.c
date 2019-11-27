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

		
	/*char *name[] = { "���ڵ�", "�̻���Ǯ", "�̻��ؾ�", "��ī��", "������", "Ǫ��", "�Ḹ��", "�̺���" };
	char *type[] = { "ǮŸ��", "��Ÿ��", "��Ÿ��", "���л�Ÿ��", "������Ÿ��" };
	char *nick[] = { "��", "��", "��ġ", "�糢" };
	printf("�̸��� �Է��ϼ���");
	scanf("%s", pokemon->name);
	printf("Ÿ���� �Է��ϼ���");
	scanf("%s", pokemon->type);
	printf("������ �Է��ϼ���");
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

	printf("����� ������ ���ϸ��� �����Դϴ�.\n");
	printf("%s", my->name);
	printf("%d", my->hp);
	printf("%d", my->agress);

}


void init_mymonster(Mymonster*my, int num)
{
	char *name[] = { "���̸�", "�̻��ؾ�", "���α�" };
	char *nick[] = {"������", "�糢", "����ġ"};
	char *type[] = {"�ҼӼ�", "Ǯ�Ӽ�", "���Ӽ�"};



	if (num == 1)
	{
		strcpy(my->name, name[0]);
		strcpy(my->type, type[0]);
		strcpy(my->nick, nick[0]);
		//my->name = { "���̸�" };
		//my->nick = { "������" };
		//my->type = { "�ҼӼ�" };
		my->agress = rand() % 51 + 100;
		my->hp = rand() % 501 + 500;
		print_mymonster(my);
	}
	else if (num == 2)
	{
		strcpy(my->name, name[1]);
		strcpy(my->type, type[1]);
		strcpy(my->nick, nick[1]);
		/*my->name = "�̻��ؾ�";
		my->nick = "������";
		my->type = "Ǯ�Ӽ�";*/
		my->agress = rand() % 51 + 100;
		my->hp = rand() % 501 + 500;
		print_mymonster(my);
	}

	else if (num == 3)
	{
		strcpy(my->name, name[2]);
		strcpy(my->type, type[2]);
		strcpy(my->nick, nick[2]);
		/*my->name = "���α�";
		my->nick = "�Ϳ��";
		my->type = "���Ӽ�";*/
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
		printf("���̸��� �����߽��ϴ�.\n");
		Mymonster * fire =my; //= (Mymonster*)malloc(sizeof(Mymonster));
		init_mymonster(fire, num);


	case 2:
		printf("�̻��ؾ��� �����߽��ϴ�.\n");
		Mymonster * flower=my; //= (Mymonster*)malloc(sizeof(Mymonster));
		init_mymonster(flower, num);


	case 3:
		printf("���α⸦ �����߽��ϴ�.\n");
		Mymonster * water=my; //= (Mymonster*)malloc(sizeof(Mymonster));
		init_mymonster(water, num);
	}
}

int boolean_type(Pokemon*real, Mymonster*my)
{
	int equal;                                         //0��ȯ�� ���� ���� �Ӽ� , 1��ȯ�� ���� ���ѼӼ�, 2��ȯ�� ���� ���ѼӼ�
	int me;
	int you;

	char *type[] = { "ǮŸ��", "��Ÿ��", "��Ÿ��" };
	char arr1[20] = { my->type };
	char arr2[20] = { real->type };

	equal = strcmp(my->type, real->type);

	if (equal == 0)
	{
		printf("���� ���� ������ Ÿ���Դϴ�.");
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
		printf("��밡 ���ѼӼ��Դϴ�.");
		return 1;
	}

	else
	{
		printf("���� ���� �Ӽ��Դϴ�.");
		return 2;
	}



	/*strcpy(real->name, arr[rand() % poketnum].name);



	
	equal = strcmp(my->type, real->type);
	
	if (equal == 0)
	{
		printf("���� ���� ������ Ÿ���Դϴ�.");
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
					printf("���� �� ��Ӽ��̴�.");

				else

				
			}





		}


	}*/


}

void monster_war(int type_priority, Pokemon*real, Mymonster*my, Mymonster**mylist, int*p)
{
	int num; //��� �ο���� �����Ұ���.
	int poket_number; //���ϸ� ������ ���° ���ϸ󲨳��� �Է¹޴� ����.

	printf("�� ������ ���۵˴ϴ�...\n");
	Sleep(1000);
	printf("3...\n");
	Sleep(1000);
	printf("2..\n");
	Sleep(1000);
	printf("1..����!\n");


	if (type_priority == 0)
	{
		do
		{
			printf("���� �Ӽ��̱� ���� ���� �����Ѵ٤��̾�!!!!\n\n\n");
			Sleep(2000);
			printf("�� ������ �°� ��밡 �������ϴ�. ����� ü���� %d��ŭ �����߽��ϴ�.\n\n", my->agress*0.5);
			real->hp = (real->hp) - (my->agress*0.5);

			printf("��밡 �����ؿ´� ���ҷӱ�!!��\n\n");
			Sleep(2000);
			printf("����� ������ �°� �� ü���� %d��ŭ �����߽��ϴ�.", real->agress*0.5);
			my->hp = (my->hp) - (real->agress*0.5);

		} while (my->hp >= 0 && real->hp >= 0);
		
		if (my->hp <= 0)
		{
			printf("���￡�� �й��߽��ϴ�...\n");
			printf("��� �ο�ðڽ��ϱ�?? 1. ��� �ο�� 2. �����Ѵ�.\n");
			scanf("%d", &num);

			if (num == 1)
			{
				//���� �������� ���ϸ� �������� �Լ�.
				int a = display_mypoketmon(mylist, p);

				if (a == 1)
					printf("���̻� ������ ���Ͱ� ���� ������ ����������....");
				
				if (a == 2)
				{
					int c;
					printf("���° ���ϸ��� �����ðڽ��ϱ�?");
					scanf("%d", &c);
					my = mypoketmonlist_call(mylist, p, c);
				}


			}
			else if (num == 2)
			{
				printf("������ �����մϴ�.\n");
				return;
			}

			else
				printf("1 �Ǵ� 2 ���߿� �ϳ��� ������.");

		}
		
		if (real->hp <= 0)
		{
			if (real->hp == 0)
				printf("���ϸ��� ���� �ʰ� Ƣ����ȴ�...\n");

			printf("���￡�� �¸��߽��ϴ�!!!\n\n");
			return;
		}

	}


	if (type_priority == 1)
	{
		do
		{
			printf("���� ���ѼӼ��̶� ��밡 ���� �����ؿ´�...����������...\n\n\n");
			Sleep(2000);
			printf("������ �°� ü���� %d��ŭ ���ҵƽ��ϴ�.\n\n", real->agress*1.5);
			my->hp = (my->hp) - (real->agress*1.5);

			printf("�� ���ʴ� �̾�!!! ���ݾ�~~\n\n\n");
			Sleep(2000);
			printf("��밡 ���� ������ �°� ü���� %d��ŭ ���ҵƽ��ϴ�.\n\n", my->agress);
			real->hp = (real->hp) - (my->agress);
			
		} while (my->hp >= 0 && real->hp >= 0);
		
		if (my->hp <= 0)
		{
			printf("���￡�� �й��߽��ϴ�...\n");
			printf("��� �ο�ðڽ��ϱ�?? 1. ��� �ο�� 2. �����Ѵ�.\n");
			scanf("%d", &num);

			if (num == 1)
			{
				//���� �������� ���ϸ� �������� �Լ�.
				display_mypoketmon(mylist, p);
			}
			if (num == 2)
			{
				printf("������ �����մϴ�.\n");
				return;
			}

		}

		if (real->hp <= 0)
		{
			if (real->hp == 0)
				printf("���ϸ��� ���� �ʰ� Ƣ����ȴ�...\n");

			printf("���￡�� �¸��߽��ϴ�!!!\n\n");
			return;
		}
	}

	
	if (type_priority == 2)
	{
		do
		{
			printf("���� ���ѼӼ��̶� ���� �����Ѵ�!!�̾�!!!!\n\n\n");
			Sleep(2000);
			printf("�� ������ �°� ��밡 �������ϴ�. ����� ü���� %d��ŭ �����߽��ϴ�.\n\n", my->agress*1.5);
			real->hp = (real->hp) - (my->agress*1.5);

			printf("��밡 �����ؿ´� ���ҷӱ�!!��\n\n");
			Sleep(2000);
			printf("����� ������ �°� �� ü���� %d��ŭ �����߽��ϴ�.", real->agress);
			my->hp = (my->hp) - (real->agress);

		} while (my->hp >= 0 && real->hp >= 0);

		if (my->hp <= 0)
		{
			printf("���￡�� �й��߽��ϴ�...\n");
			printf("��� �ο�ðڽ��ϱ�?? 1. ��� �ο�� 2. �����Ѵ�.\n");
			scanf("%d", &num);

			if (num == 1)
			{
				display_mypoketmon(mylist, p);
			}
			if (num == 2)
			{
				printf("������ �����մϴ�.\n");
				return;
			}

		}

		if (real->hp <= 0)
		{
			if (real->hp == 0)
				printf("���ϸ��� ���� �ʰ� Ƣ����ȴ�...\n");
			
			printf("���￡�� �¸��߽��ϴ�!!!\n\n");
			return;
		}
	}


}




void travel_mymonster(Mymonster**mylist, Pokemon*arr, int poketnum, Pokemon*real, Mymonster*my ,int*p)
{
	int num;                       //�޴� 1. ���� 2. ���� 3. ���濭��
	int type_priority;             //0��ȯ�� ���� ���� �Ӽ� , 1��ȯ�� ���� ���ѼӼ�, 2��ȯ�� ���� ���ѼӼ�
	printf("�����ȴ���....\n");
	
	Sleep(1000);
	printf("3...\n");
	Sleep(1000);
	printf("2...\n");
	Sleep(1000);
	printf("1...\n");

	printf("���� �߰ߵƴ�!!!\n");

	printf("1. ����\t 2.����ġ��\t 3. ���濭��");
	scanf("%d", &num);
	fflush(stdin);

	if (num == 1)
	{

		real = init(real, arr, poketnum);

		printf("\n---------------------------\n");
		printf("���� ���� \n ");
		printf("�̸� : %s \n", real->name);
		printf("���ݷ� : %d \n", real->agress);
		printf("ü�� : %d \n", real->hp);
		printf("Ÿ�� : %s \n", real->type);
		printf("\n---------------------------\n");

		type_priority=boolean_type(real, my);
		
		monster_war(type_priority, real, my, mylist, p);
	
	
	
	
	}


	
	//printf("%s %s %d %d", arr[rand()%poketnum].name, arr[rand() % poketnum].type, arr[rand() % poketnum].agress, arr[rand() % poketnum].hp);
	


}

void goto_store(int*p, Wallet*pointer)
{
	int item; //���� ���ͺ�
	int num; //����
		

	printf("1.���ͺ��� 1000�� \n");
	printf("2.ȸ�������� 2500�� \n");

	printf("�����Ϸ��� �������� ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &item);

	if (item == 0)
	{
		printf("������ ���������ϴ�.");
		return;
	}


	else if (item == 1)
	{
		printf("���ͺ��� � �����Ͻðڽ��ϱ�?");
		scanf("%d", &num);
		fflush(stdin);

		if (*p < 1000 * num)
		{
			printf("���� �����Ͽ� �� ���� �����ϴ�.");
		}

		else
		{
			printf("���� %d���� ���������� ���ŵƽ��ϴ�.", num);
			*p = *p - 1000 * num;

			for (int i = 0; i < num; i++)
				pointer->numofmonsterball++; //����ü ++��� �Ҳ�~
		}
	}

	else if (item == 2)
	{
		printf("������ � �����Ͻðڽ��ϱ�?");
		scanf("%d", &num);
		fflush(stdin);

		if (*p < 2500 * num)
		{
			printf("���� �����Ͽ� �� ���� �����ϴ�.");
		}

		else
		{
			printf("���� %d���� ���������� ���ŵƽ��ϴ�.", num);
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
		printf("���� ���ϸ��� �����ϴ�.");
		return 1;
	}

	else
	{

		for (int i = 0; i < *p; i++)
		{
			printf("%d��° ���ϸ��� �̸� : %s\n", i + 1, mylist[i]->name);
			printf("%s\n", mylist[i]->type);
			printf("%d\n", mylist[i]->hp);
			printf("%d\n", mylist[i]->agress);

		}

		return 2;
	}
}


int main(void) {


	int position = -1; // ���� ���ϸ� �߰��Ҷ����� ����. 
	
	
	Wallet mywallet = {0, 0};
	int owned_money=10000;
	int*p = &owned_money;                                                                            //������� ��������

	FILE*fp = (FILE*)fopen("poketmon_list.txt", "rt");
	Pokemon*arr;
	int i, poketnum;

	fscanf(fp, "%d", &poketnum);

	arr = (Pokemon*)malloc(sizeof(Pokemon)*poketnum);

	for (i = 1; i <= poketnum; i++)
	{
		fscanf(fp, "%s %s %d %d", arr[i-1].name, arr[i-1].type, arr[i-1].agress, arr[i-1].hp );
	}                                                                                                              //������� ������ ��Ÿ�� ����Ʈ �迭�� ���� ����.


	Mymonster mylist[6];                                                                                        //���� ���� ���ϸ�.
	
	Mymonster my;                                                                                                  //�� �ɸ��� ����ü.
	
	
	
	Pokemon real;                                                                                                 //�� ����ü.

	mypoketmonlist_insert(mylist, &my, &position);
	
	int num;//� ���ϸ��� ����
	int num2;//������ ������ ���� ��������

	
	printf("=============");
	printf("  ���ϸ���  ");
	printf("press enter key");
	printf("=============");
	getchar();

	printf("����� ������� ����ּ���.");
	printf("1. ���̸� 2. �̻��ؾ� 3. ���α�");
	scanf("%d", &num);

	choice_mymonster(&my, num);


	while (1)
	{
		printf("������ �����ðڽ��ϱ�??");
		printf("1. ��  2. �ƴϿ�  3. ��������");
		scanf("%d", &num2);
		fflush(stdin);

		//������ ������ ���� ��������

		if (num2 == 1)
			travel_mymonster(mylist, arr, poketnum, &real, &my, &position);
	    else if (num2 == 2)
		{
			printf("������ �����Ͻðڽ��ϱ�?");

		}

		else if (num2 == 3)
		{
			printf("���� ���� �ݾ� : %d\n", owned_money);
			goto_store(p, &mywallet);
		}

		else
			printf("�ǹٸ� ���ڸ� �Է����ּ���.");

	}
	return 0;
		
}
