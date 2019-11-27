#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Books {

	char sym[100];
	char book_name[100];
	char writer[100];
	char pulisher[100];
	int year;
	int state;
	int order;

} BOOKS, TEMP;

BOOKS list[100];
TEMP temp[100];


void display();
void MainMenu();
void ConditionMenu();
void BorrowMenu();
void insert(BOOKS list[], int *count);
void publish_turn(BOOKS list[], int *count);
void order_turn(BOOKS list[], int *count);
void borrow_turn(BOOKS list[], int *count);
void borrow(BOOKS list[], int *count, int command);
void turnIn(int *count);
void search(BOOKS list[], int *count);
void save(BOOKS list[], int *count);
void load(BOOKS list[], int *count);


int main() {

	int command;
	int i = 0;
	int *count = 0;
	FILE *fp;


	while (1) {
		MainMenu();//도서관리 메뉴1
		scanf("%d", &command);
		while (getchar() != '\n');
		printf("\n");

		switch (command) {

		case 1:
			insert(list, &count);

			break;
		case 2:

			ConditionMenu();
			scanf("%d", &command);

			switch (command) {
			case 1:
				order_turn(list, &count);

				break;
			case 2:
				publish_turn(list, &count);


				break;
			case 3:

				borrow_turn(list, &count);
				break;
			case 4:
				break;
			}

			break;
		case 3:
			search(list, &count);
			break;
		case 4:
			BorrowMenu();
			scanf("%d", &command);
			borrow(list, &count, command);
			break;
		case 5:
			turnIn(&count);
			break;
		case 6:
			save(list, &count);
			break;
		case 7:
			load(list, &count);
			break;
		case 8:
			printf("프로그램을 종료합니다.\n");

			break;

		}
	}
	fclose(fp);
	return 0;
}

void MainMenu() {
	printf("도서관리 program \n");
	printf("\n");

	printf("1. 도서등록\n");
	printf("2. 도서현황\n");
	printf("3. 도서검색\n");
	printf("4. 도서대출\n");
	printf("5. 도서반납\n");
	printf("6. 도서파일저장\n");
	printf("7. 도서피일불러오기\n");
	printf("8. 종료\n");
	printf("\n");

	printf("번호를 입력하고 Enter > ");

}
void ConditionMenu() {
	printf("도서 현황\n");
	printf("\n");
	printf("다음의 현황 출력기준 중에서 선택하시오.\n");
	printf("1. 도서등록\n");
	printf("2. 출판년도\n");
	printf("3. 대출도서\n");
	printf("4. 이전 메뉴로");
	printf("\n");
	printf("번호를 입력하고 Enther >");

}
void BorrowMenu() {
	printf("도서 대출\n");
	printf("\n");
	printf("대출할 도서의 항목 선택\n");
	printf("\n");
	printf("1. 청구기호 입력<최대 영문 6자>\n");
	printf("2. 도서명 입력<최대 한글 10자>\n");
	printf("3. 제1 저자명 입력<최대 한글 9자>\n");
	printf("4. 이전메뉴로");
	printf("\n");
	printf("번호를 입력하고 Enther >");

}
void insert(BOOKS list[], int *count) {


	char answer = 'y';
	while (answer != 'n') {
		printf("청구기호 입력  <최대 영문 6자>  >");
		scanf("%[^\n]s", &list[*count].sym);
		while (getchar() != '\n');
		printf("도서명 입력    <최대 한글 10자> >");
		scanf("%[^\n]s", &list[*count].book_name);
		while (getchar() != '\n');
		printf("제1 저자명 입력<최대 한글 9자>  >");
		scanf("%[^\n]s", &list[*count].writer);
		while (getchar() != '\n');
		printf("발행사 입력    <최대 한글 7자>  >");
		scanf("%[^\n]s", &list[*count].pulisher);
		while (getchar() != '\n');
		printf("출판년도 입력  <정수 4자>       >");
		scanf("%d", &list[*count].year);
		list[*count].state = 1;
		list[*count].order = *count;
		while (getchar() != '\n');
		*count += 1;
		printf("도서 등록을 계속할 것인가요?(y/n)");
		answer = getchar();
		while (getchar() != '\n');

	}

}
void display() {

	printf("\n");
	printf("청구기호  서명                저자                발행사            출판년도  상태\n");
	printf("----------------------------------------------------------------------------------\n");

}
void publish_turn(BOOKS list[], int *count) {
	int i, j;
	BOOKS temp;
	for (i = 0; i < *count; i++) {
		for (j = 0; j < *count - i - 1; j++) {
			if (list[j].year > list[j + 1].year) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	printf("도서 등록 현황<출판년도 기준>: 총%d권\n", *count);
	display();
	for (i = 0; i < *count; i++) {
		printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
		if (list[i].state == 1) {
			printf("정상\n");
		}
		else if (list[i].state == 0) {
			printf("대출\n");
		}

	}

}
void order_turn(BOOKS list[], int *count) {
	int i, j;
	BOOKS temp;
	for (i = 0; i < *count; i++) {
		for (j = 0; j < *count - i - 1; j++) {
			if (list[j].order > list[j + 1].order) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}

	}
	printf("도서 등록 현황: 총%d권\n", *count);
	display();
	for (i = 0; i < *count; i++) {
		printf("%-4s      %-4s                %-4s                %-4s              %-4d ", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
		if (list[i].state == 1) {
			printf("정상\n");
		}
		else if (list[i].state == 0) {
			printf("대출\n");
		}

	}
}
void borrow_turn(BOOKS list[], int *count) {
	int i = 0;
	int ct = 0;
	char st[10] = "대출";
	display();
	for (i = 0; i < *count; i++) {
		if (list[i].state == 0) {
			ct++;
			printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
			printf("대출\n");

		}

	}
	printf("\n");
	printf("총 대출 도서 : %d\n", ct);
}
void borrow(BOOKS list[], int *count, int command) {
	char find[100];
	int Bn;
	int con = 0;
	int i = 0;
	switch (command) {
	case 1:
		printf("청구기호 입력  <최대 영문 6자>  >");
		scanf("%s", &find);
		printf("\n");
		printf("검색결과\n");
		display();
		for (i = 0; i < *count; i++) {
			if (strcmp(list[i].sym, find) == 0) {
				con = 1;
				printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
				if (list[i].state == 1) {
					printf("정상\n");
				}
				else if (list[i].state == 0) {
					printf("대출\n");
				}
			}
		}
		printf("\n");

		if (con == 1) {

			printf("위의 도서를 대출하려면 1을, 최소는 0을 입력>");
			scanf("%d", &Bn);
			display();
			if (Bn == 1) {
				for (i = 0; i < *count; i++) {
					if (strcmp(list[i].sym, find) == 0) {
						if (list[i].state == 1) {
							list[i].state = 0;
							if (list[i].state == 0) {
								printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
								printf("대출\n");
							}
						}
						else if (list[i].state == 0) {
							printf("대출 중인 도서입니다.");
						}
					}
				}
			}

			else if (Bn == 0) {}


		}
		else if (con == 0) {
			printf("해당 도서가 존재 하지 않습니다.");
		}
		break;
	case 2:
		printf("도서명 입력    <최대 한글 10자> >");
		scanf("%s", &find);
		printf("\n");
		printf("검색결과\n");
		display();
		for (i = 0; i < *count; i++) {
			if (strcmp(list[i].book_name, find) == 0) {
				con = 1;
				printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
				if (list[i].state == 1) {
					printf("정상\n");
				}
				else if (list[i].state == 0) {
					printf("대출\n");
				}
			}
		}
		printf("\n");
		if (con == 1) {

			printf("위의 도서를 대출하려면 1을, 최소는 0을 입력>");
			scanf("%d", &Bn);
			display();
			if (Bn == 1) {
				for (i = 0; i < *count; i++) {
					if (strcmp(list[i].book_name, find) == 0) {
						if (list[i].state == 1) {
							list[i].state = 0;
							if (list[i].state == 0) {
								printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
								printf("대출\n");
							}
						}
						else if (list[i].state == 0) {
							printf("대출 중인 도서입니다.");
						}
					}
				}
			}
			else if (Bn == 0) {}
		}
		else if (con == 0) {
			printf("해당 도서가 존재 하지 않습니다.");
		}
		break;
	case 3:
		printf("저자이름 입력<최대 한글 9자>  >");
		scanf("%s", &find);
		printf("\n");
		printf("검색결과\n");
		display();
		for (i = 0; i < *count; i++) {
			if (strcmp(list[i].pulisher, find) == 0) {
				con = 1;
				printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
				if (list[i].state == 1) {
					printf("정상\n");
				}
				else if (list[i].state == 0) {
					printf("대출\n");
				}
			}
		}
		printf("\n");
		if (con == 1) {
			printf("위의 도서를 대출하려면 1을, 최소는 0을 입력>");
			scanf("%d", &Bn);
			display();
			if (Bn == 1) {
				for (i = 0; i < *count; i++) {
					if (strcmp(list[i].pulisher, find) == 0) {
						if (list[i].state == 1) {
							list[i].state = 0;
							if (list[i].state == 0) {
								printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
								printf("대출\n");
							}
						}
						else if (list[i].state == 0) {
							printf("대출 중인 도서입니다.");
						}
					}
				}
			}
			else if (Bn == 0) {}
		}
		else if (con == 0) {
			printf("해당 도서가 존재 하지 않습니다.");
		}
		break;
	case 4:
		break;
	}

}
void turnIn(int *count) {
	int i = 0;
	int n;
	int con = 0;
	printf("도서 반납\n");
	printf("\n");
	printf("반납할 도서의 청구기호<6자리>입력 후 Enter>");
	display();
	for (i = 0; i < *count; i++) {
		if (list[i].state == 0) {
			con = 1;
			printf("%s", list[i].state);
		}
	}
	printf("\n");
	if (con == 1) {
		printf("위의 도서를 반납하려면 1을, 취소는 0을 입력>");
		scanf("%d", &n);
		if (n == 1) {
			display();
			for (i = 0; i < *count; i++) {
				if (list[i].state == 0) {
					printf("%s\n", list[i].state);
					list[i].state = 1;
					printf("%s\n", list[i].state);
				}
			}
		}
		else if (n == 0) {}
	}
	else if (con == 0) {
		printf("해당 도서 및 대출중인 도서가 존재 하지 않습니다.");
	}

}
void search(BOOKS list[], int *count) {
	int n, i;
	int con = 0;
	char find[100];
	printf("도서 검색\n\n");
	printf("검색할 도서의 항목 선택\n\n");

	printf("1. 청구기호 입력<최대 영문 6자리>\n");
	printf("2. 도서명입력<최대 한글 10자리>\n");
	printf("3. 제1 저자명 입력<최대 한글 9자리>\n");
	printf("4. 이전 메뉴로\n\n");

	printf("번호를 입력하고 Enter > \n");
	scanf("%d", &n);
	switch (n) {
	case 1:
		printf("검색할 도서의 청구기호를 입력하고 Enter>");
		printf("청구기호 입력<최대 영문 6자리>");
		scanf("%s", &find);
		printf("\n");

		printf("검색결과\n");
		display();
		for (i = 0; i < *count; i++) {
			if (strncmp(find, list[i].sym, strlen(find)) == 0) {
				con = 1;
				printf("%s    %s    %s    %s    %d    ", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
				if (list[i].state == 0)
					printf("정상\n");
				else
					printf("대출\n");
			}
			else
				NULL;

		}
		if (con == 0)
			printf("해당도서가 존재하지 않습니다.\n");
		break;
	case 2:
		printf("검색할 도서의 도서명을 입력하고 Enter\n");
		printf("도서명입력<최대 한글 10자리>");
		scanf("%s", &find);
		printf("\n");

		printf("검색결과\n");
		display();
		for (i = 0; i < *count; i++) {
			if (strcmp(find, list[i].book_name) == 0) {
				con = 1;
				printf("%s    %s    %s    %s    %d    ", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
				if (list[i].state == 0)
					printf("정상\n");
				else
					printf("대출\n");
			}
			else
				NULL;
		}
		if (con == 0)
			printf("해당도서가 존재하지 않습니다.\n");
		break;
	case 3:
		printf("검색할 도서의 제1 저자명을 입력하고 Enter\n");
		printf("제1 저자명 입력<최대 한글 9자리>");
		scanf("%s", find);
		printf("\n");

		printf("검색결과\n");
		display();
		for (i = 0; i < *count; i++) {
			if (strcmp(find, list[i].writer) == 0) {
				con = 1;
				printf("%s    %s    %s    %s    %d    ", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
				if (list[i].state == 0)
					printf("정상\n");
				else
					printf("대출\n");
			}
			else
				NULL;

		}
		if (con == 0)
			printf("해당도서가 존재하지 않습니다.\n");
		break;
	case 4:
		printf("이전 메뉴로");
		break;
	}
}
void save(BOOKS list[], int *count) {

	FILE *fp = fopen("book_management.txt", "wb");
	int i;

	if (fp != NULL) {
		for (i = 0; i < *count; i++) {
			//fprintf(fp, "%s %s %s %s %d %d \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year, list[i].state);
			fwrite(list, sizeof(BOOKS), 100, fp);
		}
	}
	fclose(fp);
}
void load(BOOKS list[], int *count) {
	FILE *fp;
	int i = 0;
	if ((fp = fopen("book_management.txt", "rb")) == NULL)
		fprintf(stderr, "파일 %s 를 열 수 없습니다", "book_management.bin");

	while (!feof(fp)) {

		fscanf(fp, "%s %s %s %s %d %d", &list[*count].sym, &list[*count].book_name, &list[*count].writer, &list[*count].pulisher, &list[*count].year, &list[*count].state);
		
		*count += 1;
	}

	fclose(fp);
}