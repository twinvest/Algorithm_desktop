#include <stdio.h>

int main(void)

{

	int n;

	int line, space, star;



	printf("����:");

	scanf_s("%d", &n);//�Է�

	for (line = 0; line < n; line++)//line: 0~n-1

	{

		for (space = 0; space <(n - line - 1); space++)//���� n-line-1��

		{

			putchar(' ');

		}

		for (star = 0; star < (2 * line + 1); star++)//�� 2*line +1��

		{

			putchar('*');

		}

		putchar('\n');//����

	}

	for (line = n - 2; line >= 0; line--)//line:n-2 ~ 0

	{

		for (space = 0; space < (n - line - 1); space++)//���� n-line-1��

		{

			putchar(' ');

		}

		for (star = 0; star < (2 * line + 1); star++)//�� 2*line +1��

		{

			putchar('*');

		}

		putchar('\n');//����

	}

	return 0;

}