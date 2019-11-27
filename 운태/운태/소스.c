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
		MainMenu();//�������� �޴�1
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
			printf("���α׷��� �����մϴ�.\n");

			break;

		}
	}
	fclose(fp);
	return 0;
}

void MainMenu() {
	printf("�������� program \n");
	printf("\n");

	printf("1. �������\n");
	printf("2. ������Ȳ\n");
	printf("3. �����˻�\n");
	printf("4. ��������\n");
	printf("5. �����ݳ�\n");
	printf("6. ������������\n");
	printf("7. �������Ϻҷ�����\n");
	printf("8. ����\n");
	printf("\n");

	printf("��ȣ�� �Է��ϰ� Enter > ");

}
void ConditionMenu() {
	printf("���� ��Ȳ\n");
	printf("\n");
	printf("������ ��Ȳ ��±��� �߿��� �����Ͻÿ�.\n");
	printf("1. �������\n");
	printf("2. ���ǳ⵵\n");
	printf("3. ���⵵��\n");
	printf("4. ���� �޴���");
	printf("\n");
	printf("��ȣ�� �Է��ϰ� Enther >");

}
void BorrowMenu() {
	printf("���� ����\n");
	printf("\n");
	printf("������ ������ �׸� ����\n");
	printf("\n");
	printf("1. û����ȣ �Է�<�ִ� ���� 6��>\n");
	printf("2. ������ �Է�<�ִ� �ѱ� 10��>\n");
	printf("3. ��1 ���ڸ� �Է�<�ִ� �ѱ� 9��>\n");
	printf("4. �����޴���");
	printf("\n");
	printf("��ȣ�� �Է��ϰ� Enther >");

}
void insert(BOOKS list[], int *count) {


	char answer = 'y';
	while (answer != 'n') {
		printf("û����ȣ �Է�  <�ִ� ���� 6��>  >");
		scanf("%[^\n]s", &list[*count].sym);
		while (getchar() != '\n');
		printf("������ �Է�    <�ִ� �ѱ� 10��> >");
		scanf("%[^\n]s", &list[*count].book_name);
		while (getchar() != '\n');
		printf("��1 ���ڸ� �Է�<�ִ� �ѱ� 9��>  >");
		scanf("%[^\n]s", &list[*count].writer);
		while (getchar() != '\n');
		printf("����� �Է�    <�ִ� �ѱ� 7��>  >");
		scanf("%[^\n]s", &list[*count].pulisher);
		while (getchar() != '\n');
		printf("���ǳ⵵ �Է�  <���� 4��>       >");
		scanf("%d", &list[*count].year);
		list[*count].state = 1;
		list[*count].order = *count;
		while (getchar() != '\n');
		*count += 1;
		printf("���� ����� ����� ���ΰ���?(y/n)");
		answer = getchar();
		while (getchar() != '\n');

	}

}
void display() {

	printf("\n");
	printf("û����ȣ  ����                ����                �����            ���ǳ⵵  ����\n");
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
	printf("���� ��� ��Ȳ<���ǳ⵵ ����>: ��%d��\n", *count);
	display();
	for (i = 0; i < *count; i++) {
		printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
		if (list[i].state == 1) {
			printf("����\n");
		}
		else if (list[i].state == 0) {
			printf("����\n");
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
	printf("���� ��� ��Ȳ: ��%d��\n", *count);
	display();
	for (i = 0; i < *count; i++) {
		printf("%-4s      %-4s                %-4s                %-4s              %-4d ", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
		if (list[i].state == 1) {
			printf("����\n");
		}
		else if (list[i].state == 0) {
			printf("����\n");
		}

	}
}
void borrow_turn(BOOKS list[], int *count) {
	int i = 0;
	int ct = 0;
	char st[10] = "����";
	display();
	for (i = 0; i < *count; i++) {
		if (list[i].state == 0) {
			ct++;
			printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
			printf("����\n");

		}

	}
	printf("\n");
	printf("�� ���� ���� : %d\n", ct);
}
void borrow(BOOKS list[], int *count, int command) {
	char find[100];
	int Bn;
	int con = 0;
	int i = 0;
	switch (command) {
	case 1:
		printf("û����ȣ �Է�  <�ִ� ���� 6��>  >");
		scanf("%s", &find);
		printf("\n");
		printf("�˻����\n");
		display();
		for (i = 0; i < *count; i++) {
			if (strcmp(list[i].sym, find) == 0) {
				con = 1;
				printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
				if (list[i].state == 1) {
					printf("����\n");
				}
				else if (list[i].state == 0) {
					printf("����\n");
				}
			}
		}
		printf("\n");

		if (con == 1) {

			printf("���� ������ �����Ϸ��� 1��, �ּҴ� 0�� �Է�>");
			scanf("%d", &Bn);
			display();
			if (Bn == 1) {
				for (i = 0; i < *count; i++) {
					if (strcmp(list[i].sym, find) == 0) {
						if (list[i].state == 1) {
							list[i].state = 0;
							if (list[i].state == 0) {
								printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
								printf("����\n");
							}
						}
						else if (list[i].state == 0) {
							printf("���� ���� �����Դϴ�.");
						}
					}
				}
			}

			else if (Bn == 0) {}


		}
		else if (con == 0) {
			printf("�ش� ������ ���� ���� �ʽ��ϴ�.");
		}
		break;
	case 2:
		printf("������ �Է�    <�ִ� �ѱ� 10��> >");
		scanf("%s", &find);
		printf("\n");
		printf("�˻����\n");
		display();
		for (i = 0; i < *count; i++) {
			if (strcmp(list[i].book_name, find) == 0) {
				con = 1;
				printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
				if (list[i].state == 1) {
					printf("����\n");
				}
				else if (list[i].state == 0) {
					printf("����\n");
				}
			}
		}
		printf("\n");
		if (con == 1) {

			printf("���� ������ �����Ϸ��� 1��, �ּҴ� 0�� �Է�>");
			scanf("%d", &Bn);
			display();
			if (Bn == 1) {
				for (i = 0; i < *count; i++) {
					if (strcmp(list[i].book_name, find) == 0) {
						if (list[i].state == 1) {
							list[i].state = 0;
							if (list[i].state == 0) {
								printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
								printf("����\n");
							}
						}
						else if (list[i].state == 0) {
							printf("���� ���� �����Դϴ�.");
						}
					}
				}
			}
			else if (Bn == 0) {}
		}
		else if (con == 0) {
			printf("�ش� ������ ���� ���� �ʽ��ϴ�.");
		}
		break;
	case 3:
		printf("�����̸� �Է�<�ִ� �ѱ� 9��>  >");
		scanf("%s", &find);
		printf("\n");
		printf("�˻����\n");
		display();
		for (i = 0; i < *count; i++) {
			if (strcmp(list[i].pulisher, find) == 0) {
				con = 1;
				printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
				if (list[i].state == 1) {
					printf("����\n");
				}
				else if (list[i].state == 0) {
					printf("����\n");
				}
			}
		}
		printf("\n");
		if (con == 1) {
			printf("���� ������ �����Ϸ��� 1��, �ּҴ� 0�� �Է�>");
			scanf("%d", &Bn);
			display();
			if (Bn == 1) {
				for (i = 0; i < *count; i++) {
					if (strcmp(list[i].pulisher, find) == 0) {
						if (list[i].state == 1) {
							list[i].state = 0;
							if (list[i].state == 0) {
								printf("%s %s %s %s \n", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
								printf("����\n");
							}
						}
						else if (list[i].state == 0) {
							printf("���� ���� �����Դϴ�.");
						}
					}
				}
			}
			else if (Bn == 0) {}
		}
		else if (con == 0) {
			printf("�ش� ������ ���� ���� �ʽ��ϴ�.");
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
	printf("���� �ݳ�\n");
	printf("\n");
	printf("�ݳ��� ������ û����ȣ<6�ڸ�>�Է� �� Enter>");
	display();
	for (i = 0; i < *count; i++) {
		if (list[i].state == 0) {
			con = 1;
			printf("%s", list[i].state);
		}
	}
	printf("\n");
	if (con == 1) {
		printf("���� ������ �ݳ��Ϸ��� 1��, ��Ҵ� 0�� �Է�>");
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
		printf("�ش� ���� �� �������� ������ ���� ���� �ʽ��ϴ�.");
	}

}
void search(BOOKS list[], int *count) {
	int n, i;
	int con = 0;
	char find[100];
	printf("���� �˻�\n\n");
	printf("�˻��� ������ �׸� ����\n\n");

	printf("1. û����ȣ �Է�<�ִ� ���� 6�ڸ�>\n");
	printf("2. �������Է�<�ִ� �ѱ� 10�ڸ�>\n");
	printf("3. ��1 ���ڸ� �Է�<�ִ� �ѱ� 9�ڸ�>\n");
	printf("4. ���� �޴���\n\n");

	printf("��ȣ�� �Է��ϰ� Enter > \n");
	scanf("%d", &n);
	switch (n) {
	case 1:
		printf("�˻��� ������ û����ȣ�� �Է��ϰ� Enter>");
		printf("û����ȣ �Է�<�ִ� ���� 6�ڸ�>");
		scanf("%s", &find);
		printf("\n");

		printf("�˻����\n");
		display();
		for (i = 0; i < *count; i++) {
			if (strncmp(find, list[i].sym, strlen(find)) == 0) {
				con = 1;
				printf("%s    %s    %s    %s    %d    ", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
				if (list[i].state == 0)
					printf("����\n");
				else
					printf("����\n");
			}
			else
				NULL;

		}
		if (con == 0)
			printf("�ش絵���� �������� �ʽ��ϴ�.\n");
		break;
	case 2:
		printf("�˻��� ������ �������� �Է��ϰ� Enter\n");
		printf("�������Է�<�ִ� �ѱ� 10�ڸ�>");
		scanf("%s", &find);
		printf("\n");

		printf("�˻����\n");
		display();
		for (i = 0; i < *count; i++) {
			if (strcmp(find, list[i].book_name) == 0) {
				con = 1;
				printf("%s    %s    %s    %s    %d    ", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
				if (list[i].state == 0)
					printf("����\n");
				else
					printf("����\n");
			}
			else
				NULL;
		}
		if (con == 0)
			printf("�ش絵���� �������� �ʽ��ϴ�.\n");
		break;
	case 3:
		printf("�˻��� ������ ��1 ���ڸ��� �Է��ϰ� Enter\n");
		printf("��1 ���ڸ� �Է�<�ִ� �ѱ� 9�ڸ�>");
		scanf("%s", find);
		printf("\n");

		printf("�˻����\n");
		display();
		for (i = 0; i < *count; i++) {
			if (strcmp(find, list[i].writer) == 0) {
				con = 1;
				printf("%s    %s    %s    %s    %d    ", list[i].sym, list[i].book_name, list[i].writer, list[i].pulisher, list[i].year);
				if (list[i].state == 0)
					printf("����\n");
				else
					printf("����\n");
			}
			else
				NULL;

		}
		if (con == 0)
			printf("�ش絵���� �������� �ʽ��ϴ�.\n");
		break;
	case 4:
		printf("���� �޴���");
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
		fprintf(stderr, "���� %s �� �� �� �����ϴ�", "book_management.bin");

	while (!feof(fp)) {

		fscanf(fp, "%s %s %s %s %d %d", &list[*count].sym, &list[*count].book_name, &list[*count].writer, &list[*count].pulisher, &list[*count].year, &list[*count].state);
		
		*count += 1;
	}

	fclose(fp);
}