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


	char *name[] = { "파이리", "꼬부기", "이상해씨", "피카츄" };
	char *type[] = { "불", "물", "풀", "전기" };
	char *nick[] = { "잉", "앙", "복치", "톨끼" };
	/* printf("이름을 입력하세요");
		  25           scanf("%s", pokemon->name);
		  26           printf("타입을 입력하세요");
		  27           scanf("%s", pokemon->type);
		  28           printf("별명을 입력하세요");
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

	printf("몇마리??");
	fscanf(fp, "%d", &num);

	fclose(fp);

	arr = (Pokemon*)malloc(sizeof(Pokemon)*num);

	FILE*fp2 = (FILE*)fopen("twinvest2.txt", "wt");

	for (i = 0; i < num; i++)

		init(&arr[i]);


	for (i = 0; i < num; i++) {


		fprintf(fp2, "이름 : %s\n", arr[i].name);

		fprintf(fp2, "타입 : %s\n", arr[i].type);

		fprintf(fp2, "체력 : %d\n", arr[i].hp);


	}

	fclose(fp2);
	free(arr);


}
