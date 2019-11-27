
#include <stdio.h>
#include <stdlib.h>

int main()
{

	int num1, num2, num3;
	int count1 = 0;
	int count2 = 0;

	printf("숫자를 입력하세요.");
	scanf_s("%d", &num1);
	scanf_s("%d", &num2);
	num3 = num1;
	for (int i = num1; i <= num2; i++)
	{
		num1 = i;
		count2 = 0;
		while (1) {
			if (num1 == 1)
			{
				++count2;
				if (count2 > count1) {
					count1 = count2;
				}
				break;
			}

			else if (num1 % 2 == 0)
			{
				++count2;
				num1 = num1 / 2;
			}
			else
			{
				++count2;
				num1 = (num1 * 3) + 1;
			}
		}

	}

	printf("%d와 %d와 사이의 최대 사이클 : %d\n", num3, num2, count1);

	return 0;
}
