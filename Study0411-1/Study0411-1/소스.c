#include<stdio.h>

typedef struct ArrStruct{

char**nabi;
char**mole;
int size;

}ArrStruct;


void print(ArrStruct *arr)
{
	int i, j;
	for (i = 0; i < arr->size; i++)
	{
		printf("\n");
		for (j = 0; j < arr->size; j++)
		{
			printf("%c", arr->mole[i][j]);
		}
	}

	printf("\n\n");

	for (i = 0; i < arr->size; i++)
	{
		printf("\n");
		for (j = 0; j < arr->size; j++)
		{
			printf("%c", arr->nabi[i][j]);
		}
	}
	
}



void create(ArrStruct*arr, int num) {

	arr->size = num;
	int i, j;
	int center=num/2;

	//나비 동적할당끝
	arr->nabi = (char**)malloc(sizeof(char*)*num);
	for (i = 0; i < num; i++)
	{
		arr->nabi[i] = (char*)malloc(sizeof(char)*num);
	}

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (j<=center)
			{
				if (j <= i && i < num - j)
					arr->nabi[i][j] = '*';

				else
					arr->nabi[i][j] = ' ';
			}

			else
			{
				if(i <= j && i >= num - (j+1))
					arr->nabi[i][j] = '*';

				else
					arr->nabi[i][j] = ' ';

			}
		

		}
	}




			
	//모래 동적할당끝
	arr->mole = (char**)malloc(sizeof(char*)*num);
	for (i = 0; i < num; i++)
	{
		arr->mole[i] = (char*)malloc(sizeof(char)*num);
	}

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (i <= center) //위에삼각형
			{
				if (i <= j && j < (num - i))
					arr->mole[i][j] = '*';

				else
					arr->mole[i][j] = ' ';
				
			}

			else// 밑에 삼각형
			{
				if (j <= i  && j>= num-(i+1) )//이 부분이 제일 힘듦....num-i+1
					arr->mole[i][j] = '*';

				else
					arr->mole[i][j] = ' ';
				
			}

		}
	}



}


int main(void)
{
	int i;
	int num;
		
	printf("num값을 입력해주세요.");
	scanf("%d", &num);

	if (num % 2 == 0)
	{
		printf("num값을 홀수로 다시 입력해주세요.");
		scanf("%d", &num);
	}

	ArrStruct*a = (ArrStruct*)malloc(sizeof(ArrStruct));

		
	create(a, num);
	print(a);


}