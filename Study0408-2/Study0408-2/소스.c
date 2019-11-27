#include<stdio.h>
#include<string.h>
int main()
{
	int count = 0, index = 0, N, start, print = 0;
	char str[502];
	scanf("%s", str);
	N = strlen(str);
	//printf("배열의 길이는 %d\n", N);


	while (index<N)
	{
		count = 0, start = index;
		
		while (str[index] == 'X' && index<N) 
			count++, index++;
		
		
		if (count == 0)
			index++;



		if (count > 0)
		{
			if (count % 4 == 0 || count % 4 == 2)
			{
				print++;
				for (int i = 0; i < (count / 4) * 4; i++)
					str[start++] = 'A';

				count %= 4;
				for (int i = 0; i < count; i++) 
					str[start++] = 'B';
			}
			else
			{
				printf("-1");
				return 0;
			}
		}
	}
	//printf("프린트 : %d\n\n", print);

	if (print > 0)
		printf("%s", str);
	
	else if(print == 0 && str[0] == '.')
		printf("%s", str);

	else
		printf("-1");

	
}