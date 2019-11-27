#include<stdio.h>

typedef struct book
{
	char name[16];
	char phoneNum[14];
}book;


void showinfo(book*b1)
{
	printf("%s\n", b1->name);
	printf("%s\n", b1->phoneNum);
}


int main()
{
	book arr[2];

	for (int i = 0; i < 2; i++)
	{
		printf("이름 : "); scanf("%s", arr[i].name);
		printf("전화번호 : "); scanf("%s", arr[i].phoneNum);

		printf("\n\n");
	}

	for(int i=0; i<2; i++)
	{
		showinfo(&arr[i]);
	}
	


}