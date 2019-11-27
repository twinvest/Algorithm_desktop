#include<stdio.h>
int main()
{
	int Test_case;
	int Card_number;
	char temp;
	scnaf("%d", &Test_case);
	scanf("%d", &Card_number);

	
	
	for (int i = 0; i < Test_case; i++)
	{
		char * p = (char*)malloc(sizeof(char)*Card_number);
		
		for (int j = 0; j < Card_number; j++)
		{
			scanf("%c", &temp);
			if (p[j] < temp)
			{
				p[j + 1] = p[j];
				p[j] = temp;
			}
			else if (p[j] > temp)
			{

			}
			else if(p[j]==temp)
			{

			}
		}
	}


}