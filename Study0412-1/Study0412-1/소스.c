 #include <stdio.h>
 #include <time.h>
 #include <stdlib.h>
 #include <string.h>

typedef struct Pokemon {


	char name[20];
	char type[20];
	char nick[20];
	int  agress;
	int  hp;


} Pokemon;

void init(Pokemon *pokemon) {


	char *name[] = { "���̸�", "���α�", "�̻��ؾ�", "��ī��" };
	char *type[] = { "��", "��", "Ǯ", "����" };
	char *nick[] = { "��", "��", "��ġ", "�糢" };
	/* printf("�̸��� �Է��ϼ���");
		  25           scanf("%s", pokemon->name);
		  26           printf("Ÿ���� �Է��ϼ���");
		  27           scanf("%s", pokemon->type);
		  28           printf("������ �Է��ϼ���");
		  29           scanf("%s", pokemon->nick);*/
	strcpy(pokemon->name, name[rand() % 4]);
	strcpy(pokemon->type, type[rand() % 4]);
	strcpy(pokemon->nick, nick[rand() % 4]);

	(pokemon->agress) = rand() % 500 + 500;
	(pokemon->hp) = rand() % 50 + 100;


}

int main() {

	FILE*fp = (FILE*)fopen("twinvest.txt", "rt");
	// File*fp2=(File*)fopen("twinvest.txt", "wt");


	Pokemon *arr;
	int i, num;
	srand((unsigned)time(NULL));

	printf("���??");
	fscanf(fp, "%d", &num);

	fclose(fp);

	arr = (Pokemon*)malloc(sizeof(Pokemon)*num);

	FILE*fp2 = (FILE*)fopen("twinvest2.txt", "wt");

	for (i = 0; i < num; i++)

		init(&arr[i]);


	for (i = 0; i < num; i++) {


		fprintf(fp2, "�̸� : %s\n", arr[i].name);

		fprintf(fp2, "Ÿ�� : %s\n", arr[i].type);

		fprintf(fp2, "ü�� : %d\n", arr[i].hp);


	}

	fclose(fp2);
	free(arr);


}
