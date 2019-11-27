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

	//���� �����Ҵ糡
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




			
	//�� �����Ҵ糡
	arr->mole = (char**)malloc(sizeof(char*)*num);
	for (i = 0; i < num; i++)
	{
		arr->mole[i] = (char*)malloc(sizeof(char)*num);
	}

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (i <= center) //�����ﰢ��
			{
				if (i <= j && j < (num - i))
					arr->mole[i][j] = '*';

				else
					arr->mole[i][j] = ' ';
				
			}

			else// �ؿ� �ﰢ��
			{
				if (j <= i  && j>= num-(i+1) )//�� �κ��� ���� ����....num-i+1
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
		
	printf("num���� �Է����ּ���.");
	scanf("%d", &num);

	if (num % 2 == 0)
	{
		printf("num���� Ȧ���� �ٽ� �Է����ּ���.");
		scanf("%d", &num);
	}

	ArrStruct*a = (ArrStruct*)malloc(sizeof(ArrStruct));

		
	create(a, num);
	print(a);


}