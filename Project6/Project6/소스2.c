#include<stdio.h>

int maint(void)
{

}

void read(Scanner S) {
	int i = 0;

	name = S.next();

	bMale = S.next().equals("M");

	Birthyear = S.nextInt();

	Deathyear = S.nextInt();

	S.nextLine();

	while (S.hasNext()) {
		LIFE.add(i, S.nextLine());
		if (LIFE.get(i).equals(""))
			break;
		i++;
	}

}





/*#include <stdio.h>
#define DIFF_ABS( X , Y ) ( (X)>(Y) ? (X)-(Y) : (Y)-(X) )
int main(void)
{
	printf("�� ���� �� : %d \n", DIFF_ABS( 5 , 7 ));
	printf("�� ���� �� : %g \n", DIFF_ABS( 1.8 , -1.4 ));
	return 0;
}*/



/*{
	FILE*src = fopen("�ؿܼ�������.jpg","rb");
	FILE*des = fopen("tw.jpg", "wb");
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL) {
		puts("���� ���� ����!");
		return -1;
	}

	while (1)
	{
		readCnt = fread((void*)buf, 1, sizeof(buf), src);
		
		if (readCnt < sizeof(buf))
		{
			if(feof(src)!=0)
			{
				fwrite((void*)buf, 1, readCnt, des);
				puts("���Ϻ���Ϸ�");
				break;
			}
			else
				puts("���Ϻ��� ����");
			break;
		}
		fwrite((void*)buf, 1, sizeof(buf), des);
	}

	fclose(src);
	fclose(des);
	return 0;
	
}*/





/*void RemoveBSN(char str[])
{
	int len = strlen(str);
	str[len - 1] = 0;
}*/
/*struct point
{
	int xpos;
	int ypos;
};
struct circle
{
	double radius;
	struct point*center;
};

int main(void)
{
	struct point cen = { 2, 7 };
	double rad = 5.5;

	struct circle ring = { rad, &cen };

	printf("���� ������ : %g \n", ring.radius);
	pritnf("���� �߽� [%d, %d] \n", (ring.center)->xpos, (ring.center)->ypos);

	return 0;
}*/

	/*char str1[20];
	char str2[20];
	printf("���ڿ� �Է� 1: ");
	scanf("%s", str1);

	printf("���ڿ� �Է� 2: ");
	scanf("%s", str2);

	if (!strcmp(str1, str2))
	{
		puts("�� ���ڿ��� �Ϻ��� �����մϴ�.");
	}
	else
	{
		puts("�� ���ڿ��� �������� �ʽ��ϴ�.");

		if (!strncmp(str1, str2, 3))
			puts("�׷��� �� �� ���ڴ� �����մϴ�.");
	}
	return 0;*/


	/*char str1[20] = "first~";
	char str2[20] = "second";

	char str3[20] = "simple num: ";
	char str4[20] = "1234567890";

	//case1
	strcat(str1, str2);
	puts(str1);


	//case2
	strncat(str3, str4, 7);
	puts(str3);

	return 0;*/


	/*char str1[20] = "1234567890";
	char str2[20];
	char str3[5];


	//case1
	strcpy(str2, str1);
	puts(str2);

	//case2
	strncpy(str3, str1, sizeof(str3));
	puts(str3);

	//case3
	strncpy(str3, str1, sizeof(str3)-1);
	str3[sizeof(str3) - 1] = 0;
	puts(str3);
	return 0;*/




	/*char str[] = "1234567";
	printf("strlen�� �̿��� str�� ũ�� : %d \n", strlen(str));
	printf("sizeof �����ڸ� �̿��� str�� ũ�� : %d \n", sizeof(str));*/


	/*char str1[] = "good morning!";
	char str2[100];

	printf("str1�� good morning��! \n");
	printf("str2�� ���ڿ��Է��ϼ�! : ");

	fgets(str2, sizeof(str2), stdin);

	printf("str1 ���� : %d \n", sizeof(str1));
	printf("str2 ���� : %d \n", strlen(str2));*/





	/*void ClearLineFromReadBuffer(void)
	{
		while (getchar() != '\n');
	}




	int main(void)
	{
		char perID[7];
		char name[10];

		fputs("�ֹι�ȣ �� 6�ڸ� �Է�: ", stdout);
		fgets(perID, sizeof(perID), stdin);
		ClearLineFromReadBuffer(); //�Է¹��� �����.

		fputs("�̸��Է� : ", stdout);
		fgets(name, sizeof(name), stdin);

		printf("�ֹι�ȣ: %s \n", perID);
		printf("�̸� : %s \n", name);
		return 0;*/


		/*char str[7];
		int i;

		for (i = 0; i < 3; i++)
		{
			fgets(str, sizeof(str), stdin);
			printf("Read %d: %s \n", i + 1, str);

		}

		return 0;*/