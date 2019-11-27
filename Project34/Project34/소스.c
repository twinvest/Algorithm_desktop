#include<stdio.h>
#include<string.h>

void main(void)
{
	char str1[24];
	char str2[24];
	scanf("%s", str1);

	if (strlen(str1) == 8)
	{
		strcpy(str2, str1); // str1의 값을 str2에 복사.
		if (strncmp(str2, "possXXXX", 4)==0)
		{
			if (str2[4] == '!')
			{
				if (str2[5] == 'B')
				{
					if (str2[6] == '1')
					{
						if (str2[7] == 'E')
						{
							printf("FUNFUN R3ver5ing! Congratz!\n");
						}
					}

				}
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		printf("wrong length");
	}
}