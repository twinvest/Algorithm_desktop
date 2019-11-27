#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#pragma warning(disable:4996)


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
	int hphp;
	
} Pokemon;

typedef struct mymonster {

	char name[20];
	char nick[20];
	char type[20];
	int agress;
	int hp;
	int hphp;


} Mymonster;

Pokemon* init(Pokemon*, Pokemon*, int);
void print_mymonster(Mymonster*);
void init_mymonster(Mymonster*my, int num);
void choice_mymonster(Mymonster*my, int num);
int boolean_type(Pokemon*real, Mymonster*my);
void monster_war(int type_priority, Pokemon*real, Mymonster*my, Mymonster**mylist, int*p);
int runaway_poketmon(Pokemon*real, Mymonster*my);
void travel_mymonster(Mymonster**mylist, Pokemon*arr, int poketnum, Pokemon*real, Mymonster*my, int*p, Wallet*);
void goto_store(int*p, Wallet*pointer);
Mymonster* mypoketmonlist_call(Mymonster**mylist, int*p_position, int a);
void mypoketmonlist_insert(Mymonster**mylist, Mymonster*my, int*p_position);
int display_mypoketmon(Mymonster**mylist, int*p);


Pokemon* init(Pokemon*real, Pokemon*arr, int poketnum) {


	/*char *name[] = { "���ڵ�", "�̻���Ǯ", "�̻��ؾ�", "��ī��", "������", "Ǫ��", "�Ḹ��", "�̺���" };
	char *type[] = { "ǮŸ��", "��Ÿ��", "��Ÿ��", "���л�Ÿ��", "������Ÿ��" };
	char *nick[] = { "��", "��", "��ġ", "�糢" };*/

	strcpy(real->name, arr[rand() % poketnum].name);
	strcpy(real->type, arr[rand() % poketnum].type);
	(real->agress) = rand() % 51+100;
	(real->hp) = rand() % 501+500;
	real->hphp = real->hp;

	printf("\n============================\n");
	printf("���� ���� \n ");
	printf("�̸� : %s \n", real->name);
	printf("���ݷ� : %d \n", real->agress);
	printf("ü�� : %d \n", real->hp);
	printf("Ÿ�� : %s \n", real->type);
	printf("\n============================\n");

	
	return real;


	//printf("%s %s %d %d", arr[rand() % poketnum].name, arr[rand() % poketnum].type, arr[rand() % poketnum].agress, arr[rand() % poketnum].hp);

}




void print_mymonster(Mymonster*my)
{
	printf("=====================================\n");
	printf("�̸�   : %s\n", my->name);
	printf("ü��   : %d\n", my->hp);
	printf("���ݷ� : %d\n", my->agress);
	printf("Ÿ��   : %s\n", my->type);
	printf("=====================================\n");
}


void init_mymonster(Mymonster*my, int num)
{
	char *name[] = { "���̸�", "�̻��ؾ�", "���α�" };
	char *nick[] = { "������", "�糢", "����ġ" };
	char *type[] = { "�ҼӼ�", "Ǯ�Ӽ�", "���Ӽ�" };


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
		my->hphp = my->hp;
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
		my->hphp = my->hp;
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
		my->hphp = my->hp;
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
		Mymonster* fire = my; //= (Mymonster*)malloc(sizeof(Mymonster));
		init_mymonster(fire, num);
		break;


	case 2:
		printf("�̻��ؾ��� �����߽��ϴ�.\n");
		Mymonster* flower = my; //= (Mymonster*)malloc(sizeof(Mymonster));
		init_mymonster(flower, num);
		break;


	case 3:
		printf("���α⸦ �����߽��ϴ�.\n");
		Mymonster* water = my; //= (Mymonster*)malloc(sizeof(Mymonster));
		init_mymonster(water, num);
		break;
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
		me = strcmp(type[i], my->type);
		if (me == 0)
		{
			me = i + 1;
			break;
		}

	}

	for (int i = 0; i < 3; i++)
	{
		you = strcmp(type[i], real->type);
		if (you == 0)
		{
			you = i + 1;
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
	
		--*p;
			printf("���� �Ӽ�\n\n");
			Sleep(2000);
			printf("���� ���� ����. ����� ü���� %d��ŭ �����߽��ϴ�.\n", my->agress);
			real->hp = (real->hp) - (my->agress);

			printf("��밡 �����ؿ´�.\n");
			Sleep(2000);
			printf("����� ������ �°� �� ü���� %d��ŭ �����߽��ϴ�.\n", real->agress);
			my->hp = (my->hp) - (real->agress);

		

		if (my->hp <= 0)//���� �׾�����
		{
			//my = NULL; 
			printf("���￡�� �й��߽��ϴ�\n\n");
			printf("��� �ο�ðڽ��ϱ�?? 1. ��� �ο�� 2. �����Ѵ�.\n");
			scanf("%d", &num);

			if (num == 1)//��� �ο���� 1�϶� �ο�°Ű� �迭���� ���ϸ��� �����;���.
			{
				
				//���� �������� ���ϸ� �������� �Լ�.
				int a = display_mypoketmon(mylist, p);  //1�� ��ȯ�Ǹ� ���Ͱ� ����. 2�� ���Ͱ� �ִ� ���.

				if (a == 1)
				{
					printf("���̻� ������ ���Ͱ� ���� ������ ����������....");
					*p++;//��� �� ������ �κ� �� ��������....������;;; ���� �����ؾ��ҵ�

					for (int i = 0; i < 6; i++)
					{
						mylist[i]->hp = mylist[i]->hphp;
					}
					
				}
				if (a == 2)
				{
					int b;
					printf("���° ���ϸ��� �����ðڽ��ϱ�?");
					scanf("%d", &b);
					fflush(stdin);

					//my = mypoketmonlist_call(mylist, p, b);
					//Mymonster* mypoketmonlist_call(Mymonster**mylist, int*p_position, int a)
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
				printf("���ϸ��� ���� �ʰ� �����ƴ�...\n");

			printf("���￡�� �¸��߽��ϴ�!!!\n\n");
			return;
		}
		else //���� ü���� 0�̸��� �ƴϰ� 0�� �ƴѰ��.
		{
			printf("���� ü�� : %d\n", real->hp);
			printf("���� ü�� : %d\n", my->hp);
		}

	}


	if (type_priority == 1)
	{
		--*p;
			printf("���� ���ѼӼ�. ��밡 �����մϴ�.\n");
			Sleep(2000);
			printf("������ �°� ü���� %d��ŭ ���ҵƽ��ϴ�.\n", real->agress*2);
			my->hp = (my->hp) - (real->agress*2);

			printf("���� �����մϴ�.\n");
			Sleep(2000);
			printf("��밡 ���� ������ �°� ü���� %d��ŭ ���ҵƽ��ϴ�.\n\n", my->agress);
			real->hp = (real->hp) - (my->agress);

		

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
					int a;
					printf("���° ���ϸ��� �����ðڽ��ϱ�?");
					scanf("%d", &a);
					//my = mypoketmonlist_call(mylist, p, a);
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
				printf("���ϸ��� ���� �ʰ� �����ƴ�...\n");

			printf("���￡�� �¸��߽��ϴ�!!!\n\n");
			return;
		}
		else //���� ü���� 0�̸��� �ƴϰ� 0�� �ƴѰ��.
		{
			printf("���� ü�� : %d\n", real->hp);
			printf("���� ü�� : %d\n", my->hp);
		}

		
	}


	if (type_priority == 2)
	{
		--*p;
			printf("���� ���ѼӼ�. ���� �����մϴ�.\n");
			Sleep(2000);
			printf("����� ü���� %d��ŭ �����߽��ϴ�.\n", my->agress*2);
			real->hp = (real->hp) - (my->agress*2);

			printf("��밡 �����մϴ�.\n");
			Sleep(2000);
			printf("����� ������ �°� �� ü���� %d��ŭ �����߽��ϴ�.\n", real->agress);
			my->hp = (my->hp) - (real->agress);

		

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
					int a;
					printf("���° ���ϸ��� �����ðڽ��ϱ�?");
					scanf("%d", &a);
					//my = mypoketmonlist_call(mylist, p, a);
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
				printf("���ϸ��� ���� �ʰ� �����ƴ�...\n");

			printf("���￡�� �¸��߽��ϴ�!!!\n\n");
			return;
		}
		else //���� ü���� 0�̸��� �ƴϰ� 0�� �ƴѰ��.
		{
			printf("���� ü�� : %d\n", real->hp);
			printf("���� ü�� : %d\n", my->hp);
		}

		
	}


}

int runaway_poketmon(Pokemon*real, Mymonster*my)// 1�̸� ����ġ�µ� ���� 2�� ����ġ�µ� ����.
{
	int probability = rand() % 101; // ����ĥ Ȯ���� ��Ÿ��.

	if (real->hphp == real->hp) // ���ü���� �پ���� �ʰ� �״�� 100% ���� ü�°� ������.
	{
		if (probability <= 10)
		{
			printf("����ġ�µ� �����ߴ�!!\n");
			return 1;
		}
		else
		{
			printf("����ġ�� �����ߴ�...\n");
			return 2;
		}
	}

	else if (real->hphp *50  <= real->hp * 100 && real->hp < real->hphp)
	{
		if (probability <= 40)
		{
			printf("����ġ�µ� �����ߴ�!!\n");
			return 1;
		}
		else
		{
			printf("����ġ�� �����ߴ�...\n");
			return 2;
		}
	}

	else if(real->hphp*25 <= real->hp*100 && real->hp*100 < real->hphp*50)
	{
		if (probability <= 70)
		{
			printf("����ġ�µ� �����ߴ�!!\n");
			return 1;
		}
		else
		{
			printf("����ġ�� �����ߴ�...\n");
			return 2;
		}
	}

	else if (real->hp>=0 && real->hp*100 < real->hphp*25)
	{
		if (probability <= 90)
		{
			printf("����ġ�µ� �����ߴ�!!\n");
			return 1;
		}
		else
		{
			printf("����ġ�� �����ߴ�...\n");
			return 2;
		}
	}

	return -1;//���������� 
}

void potion_call(Wallet*mywallet, Mymonster*my)
{
	mywallet->numofpotion--;
	int recovery_mok = my->hphp;
	int recovery_namuzi = my->hphp;
	recovery_mok = (recovery_mok / 100) * 30;
	recovery_namuzi = (recovery_namuzi % 100) / 10 * 3;

	my->hp = (my->hp) + recovery_mok + recovery_namuzi;
	
}

int monsterball_call(Mymonster**mylist, Pokemon*real, Mymonster*my, Wallet*mywallet, int*p) // ��ȯ�� 1�̸� ����. 2�� ������.
{
	char name[20];
	int probability = rand() % 101;//���� Ȯ��
	
	
	printf("���� ���ͺ�!!");
	
	if (real->hphp / 2 < real->hp)
	{
		printf("ü���� �� ����ּ���....");
		mywallet->numofmonsterball--;
		return 2;
	}
	
	else if (real->hphp * 30 <= real->hp * 100 && real->hphp * 50 > real->hp * 100) // ü���� 30~50%�϶� ����Ȯ���� 30����
	{
		if (probability <= 30)
		{
			printf("���ͺ��� ���ϸ��� �����ϴ�.\n");
			printf("�̸��� �Է����ּ��� : ");
			scanf("%s", name);

			strcpy(real->name, name);
			mypoketmonlist_insert(mylist, real, p);
			return 1;
		    //mypoketmonlist_insert(Mymonster**mylist, Mymonster*my, int*p_position)
		}

		else
		{
			printf("���ϸ��� ������ �ʾҽ��ϴ�..����");
			mywallet->numofmonsterball--;
			return 2;
		}
	}

	else if (real->hphp * 30 > real->hp * 100 && real->hphp * 10 <= real->hp * 100) // ü���� 10~30%�϶� ����Ȯ���� 60����
	{
		if (probability <= 60)
		{
			printf("���ͺ��� ���ϸ��� �����ϴ�.\n");
			printf("�̸��� �Է����ּ��� : ");
			scanf("%s", name);

			strcpy(real->name, name);
			mypoketmonlist_insert(mylist, real, p);
			return 1;
			//mypoketmonlist_insert(Mymonster**mylist, Mymonster*my, int*p_position)
		}

		else
		{
			printf("���ϸ��� ������ �ʾҽ��ϴ�..����");
			mywallet->numofmonsterball--;
			return 2;
		}
	}

	else if (0<real->hp && real->hphp*10 > real->hp*100) // ü���� 0~10%�϶� ����Ȯ���� 90����
	{
		if (probability <= 90)
		{
			printf("���ͺ��� ���ϸ��� �����ϴ�.\n");
			printf("�̸��� �Է����ּ��� : ");
			scanf("%s", name);

			strcpy(real->name, name);
			mypoketmonlist_insert(mylist, real, p);
			return 1;
			//mypoketmonlist_insert(Mymonster**mylist, Mymonster*my, int*p_position)
		}

		else
		{
			printf("���ϸ��� ������ �ʾҽ��ϴ�..����");
			mywallet->numofmonsterball--;
			return 2;
		}
	}

}

void travel_mymonster(Mymonster**mylist, Pokemon*arr, int poketnum, Pokemon*real, Mymonster*my, int*p, Wallet*mywallet)
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

	printf("�߻��� ���ϸ��� ��Ÿ����!!!\n");
	printf("==========================\n");
	real = init(real, arr, poketnum); //�� ����.
	//do while���� ����� �۾ƾ��ҵ�.

	while (1)
	{
		printf("1.���� 2.����ġ�� 3. ���濭��");
		scanf("%d", &num);

		fflush(stdin);

		if (num == 1)//�����ϴ� �Լ�.
		{
			
			type_priority = boolean_type(real, my);

			monster_war(type_priority, real, my, mylist, p);

		}
		else if (num == 2)//����ġ�� �Լ�.
		{
			int run = runaway_poketmon(real, my);//run�� 1�̸� ���� 2�� ����.
			//int runaway_poketmon(Pokemon*real, Mymonster*my)
			if (run == 1)
				break;

		}
		else if (num == 3)//���濩�� �Լ�
		{
			if (mywallet->numofmonsterball == 0 && mywallet->numofpotion == 0)
			{
				printf("������ ����ֽ��ϴ�.\n");
			}

			else
			{
				printf("������ ���� : %d\n", mywallet->numofpotion );
				printf("���ͺ��� ���� : %d \n", mywallet->numofmonsterball);
				printf("�������� ����Ͻðڽ��ϱ�??\n");
				printf("1. ������� �ʴ´�. 2. ���ͺ� 3. ����");
				int item; 
				scanf("%d", &item);
				
				if (item == 1)
					break;

				else if (mywallet->numofmonsterball != 0 && item == 2)
				{

					int a = monsterball_call(mylist, real, my, mywallet, p);
					if (a == 1)
					{
						printf("������ �����ϰ� �� ������!!!!\n\n\n\n\n");

						for (int i = 0; i <= *p; i++)
						{
							printf("%d��° ���ϸ��� �̸� : %s\n", i + 1, mylist[i]->name);
							printf("%d��° ���ϸ��� Ÿ�� : %s\n", i + 1, mylist[i]->type);
							printf("%d��° ���ϸ��� ü�� : %d\n", i + 1, mylist[i]->hp);
							printf("%d��° ���ϸ��� ���ݷ� : %d\n", i + 1, mylist[i]->agress);
						}
						break;
					}

			      	//int monsterball_call(Mymonster**mylist, Pokemon*real, Mymonster*my, Wallet*mywallet, int*p) // ��ȯ�� 1�̸� ����. 2�� ������.
					
				}
				else if (mywallet->numofpotion !=0 && item == 3)
				{
	
					potion_call(mywallet, my);
					//void potion_call(Wallet*mywallet, Mymonster*my)
				}

				else
				{
					printf("����� �� �����ϴ�.");
				}
			}
		}
		else
			printf("1 �Ǵ� 2 �Ǵ� 3�߿� �����Ͻÿ�.");


		
	
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
		printf("������ ���������ϴ�.\n\n");
		return;
	}


	else if (item == 1)
	{
		printf("���ͺ��� � �����Ͻðڽ��ϱ�?");
		scanf("%d", &num);
		fflush(stdin);

		if (*p < 1000 * num)
		{
			printf("���� �����Ͽ� �� ���� �����ϴ�.\n");
		}

		else
		{
			printf("���� %d���� ���������� ���ŵƽ��ϴ�.\n", num);
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
			printf("���� �����Ͽ� �� ���� �����ϴ�.\n");
		}

		else
		{
			printf("���� %d���� ���������� ���ŵƽ��ϴ�.\n", num);
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
	
	Mymonster*newpoketmon = mylist[a - 1];


	for (int i = 0; i <= *p_position; i++)
	{
		mylist[a - 1] = mylist[a];
	}
	
	*p_position--;

	return newpoketmon;
}

void mypoketmonlist_insert(Mymonster**mylist, Mymonster*my, int*p_position)
{
	
	mylist[++*p_position] = my;

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

		for (int i = 0; i <= *p; i++)
		{
			printf("%d��° ���ϸ��� �̸� : %s\n", i + 1, mylist[i]->name);
			printf("%d��° ���ϸ��� Ÿ�� : %s\n", i + 1, mylist[i]->type);
			printf("%d��° ���ϸ��� ü�� : %d\n", i + 1, mylist[i]->hp);
			printf("%d��° ���ϸ��� ���ݷ� : %d\n", i + 1, mylist[i]->agress);
		}

		return 2;
	}
}


int main(void) {

	srand((unsigned)time(NULL));
	int position = -1; // ���� ���ϸ� �߰��Ҷ����� ����. 



	Wallet mywallet = { 0, 0 };
	int owned_money = 10000;
	int*p = &owned_money;                                                                                          //������� ��������

	FILE*fp = (FILE*)fopen("poketmon_list.txt", "rt");
	Pokemon* arr;
	int i, poketnum;

	fscanf(fp, "%d", &poketnum);

	arr = (Pokemon*)malloc(sizeof(Pokemon)*poketnum);

	for (i = 1; i <= poketnum; i++)
	{
		fscanf(fp, "%s %s %d %d", &arr[i - 1].name, &arr[i - 1].type, &arr[i - 1].agress, &arr[i - 1].hp);
	}                                                                                                              //������� ������ ��Ÿ�� ����Ʈ �迭�� ���� ����.


	Mymonster mylist[6];                                                                                        //���� ���� ���ϸ�.
	
	Mymonster my;                                                                                                  //�� �ɸ��� ����ü.
	
	Pokemon real;                                                                                                 //�� ����ü.

	
	int num;//� ���ϸ��� ����
	int num2;//������ ������ ���� ��������


	printf("================\n");
	printf("  ���ϸ���  \n");
	printf("press enter key\n");
	printf("================\n");
	getchar();

	printf("����� ������� ����ּ���.");
	printf("1. ���̸� 2. �̻��ؾ� 3. ���α�");
	scanf("%d", &num);

	choice_mymonster(&my, num);

	

	while (1)
	{
		printf("=============================\n");
		printf("������ �����ðڽ��ϱ�??");
		printf("1. ��  2. �ƴϿ�  3. ��������");
		
		scanf("%d", &num2);
		printf("=============================\n");
		
		fflush(stdin);

		//������ ������ ���� ��������

		if (num2 == 1)
		{
			mypoketmonlist_insert(mylist, &my, &position);
			travel_mymonster(mylist, arr, poketnum, &real, &my, &position, &mywallet);
		}
		else if (num2 == 2)
		{
			printf("������ �����Ͻðڽ��ϱ�?\n");


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