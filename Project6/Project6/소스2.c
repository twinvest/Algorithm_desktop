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
	printf("두 값의 차 : %d \n", DIFF_ABS( 5 , 7 ));
	printf("두 값의 차 : %g \n", DIFF_ABS( 1.8 , -1.4 ));
	return 0;
}*/



/*{
	FILE*src = fopen("해외선물강의.jpg","rb");
	FILE*des = fopen("tw.jpg", "wb");
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL) {
		puts("파일 오픈 실패!");
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
				puts("파일복사완료");
				break;
			}
			else
				puts("파일복사 실패");
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

	printf("원의 반지름 : %g \n", ring.radius);
	pritnf("원의 중심 [%d, %d] \n", (ring.center)->xpos, (ring.center)->ypos);

	return 0;
}*/

	/*char str1[20];
	char str2[20];
	printf("문자열 입력 1: ");
	scanf("%s", str1);

	printf("문자열 입력 2: ");
	scanf("%s", str2);

	if (!strcmp(str1, str2))
	{
		puts("두 문자열은 완벽히 동일합니다.");
	}
	else
	{
		puts("두 문자열은 동일하지 않습니다.");

		if (!strncmp(str1, str2, 3))
			puts("그러나 앞 세 글자는 동일합니다.");
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
	printf("strlen을 이용한 str의 크기 : %d \n", strlen(str));
	printf("sizeof 연산자를 이용한 str의 크기 : %d \n", sizeof(str));*/


	/*char str1[] = "good morning!";
	char str2[100];

	printf("str1은 good morning임! \n");
	printf("str2의 문자열입력하셈! : ");

	fgets(str2, sizeof(str2), stdin);

	printf("str1 길이 : %d \n", sizeof(str1));
	printf("str2 길이 : %d \n", strlen(str2));*/





	/*void ClearLineFromReadBuffer(void)
	{
		while (getchar() != '\n');
	}




	int main(void)
	{
		char perID[7];
		char name[10];

		fputs("주민번호 앞 6자리 입력: ", stdout);
		fgets(perID, sizeof(perID), stdin);
		ClearLineFromReadBuffer(); //입력버퍼 지우기.

		fputs("이름입력 : ", stdout);
		fgets(name, sizeof(name), stdin);

		printf("주민번호: %s \n", perID);
		printf("이름 : %s \n", name);
		return 0;*/


		/*char str[7];
		int i;

		for (i = 0; i < 3; i++)
		{
			fgets(str, sizeof(str), stdin);
			printf("Read %d: %s \n", i + 1, str);

		}

		return 0;*/