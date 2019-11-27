#include<stdio.h>

int main(void)
{
	int student;
	int answer;
	scanf("%d\n", &student);
	int cheating_student[100];
	int cheat = 0;


	for (int i = 1; i <= student; i++)
	{

		int flag=0;
		for (int j = 1; j <= 10; j++)
		{
			scanf("%d", &answer);
			if (answer == (j-1)%5+1)
				++flag;
			if (flag == 10)
				cheating_student[cheat++] = i;
				//printf("%d", i);
		}
	}

	for (int i = 0; i <= cheat-1; i++)
	{
		printf("%d\n", cheating_student[i]);
	}

	return 0;
}