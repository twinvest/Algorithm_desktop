/*#include<stdio.h>
char* call(void);

char* call(void)
{
	char arr[50] = { 0, };
	while (1)
	{
		scanf("%s", arr);
		for (int i = 0; i < sizeof(arr); i++)
		{
			if (arr[i] != '(' && arr[i] != ')')
			{
				if (arr[i] == '\0')
					return arr;
			}

		}
	}
}
int main()
{	
	int loof = 0;
	int loof2 = 0;
	int left = 0;
	int right = 0;

	while (1) //�����Է�
	{
		scanf("%d", &loof);
		if (loof >= 2 && loof <= 50) {
				break;
		}
	}
	
	do {
		loof2++;
		
		left = 0;
		right = 0;

		char * p = call();

		for (int i = 0; p == '\0'; p++, i++) //Ȯ���ϴ� �κ�. �ٽ� �˰���.
		{
			if (p[i] == '(')
				left++;
			else if (p[i] == ')')
				right++;
	
		}
		if (left == right) //��ºκ�
			printf("YES\n");
		else
			printf("NO\n");
		

	} while (loof2 < loof);
}*/

#include <stdio.h> 

#define MAXSIZE 50

int main() {

	int i, j, cnt, num;

	char arr[MAXSIZE];

	scanf("%d", &num);

	for (j = 0; j < num; j++) {

		cnt = 0;

		scanf("%s", arr);

		for (i = 0; i < MAXSIZE; i++) {

			if (arr[i] == '\0')

				break;

			if (arr[i] == '(')

				cnt++;

			else if (arr[i] == ')' && cnt > 0)

				cnt--;

			else if (arr[i] == ')' && cnt <= 0) {

				cnt--;

				break;

			}

		}

		if (cnt == 0)

			printf("YES\n");

		else

			printf("NO\n");

	}

}