#include <stdio.h>
void main() {

	int **a;
	int **b;
	int size;
	int i, j;
	int Time = -1;
	int flag = 1;

	scanf_s("%d", &size);
	a = (int**)malloc(sizeof(int*)*size);
	for (i = 0; i < size; i++)
		a[i] = (int*)malloc(sizeof(int)*size);
	
	b = (int**)malloc(sizeof(int*)*size);
	for (i = 0; i < size; i++)
		b[i] = (int*)malloc(sizeof(int)*size);
	
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	
	while (flag)
	{
		++Time;
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				b[i][j] = a[i][j];
			}
		}
		flag = 0;
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (b[i][j] == 2)
				{
					if (i != 0 && b[i - 1][j] == 0) {
						a[i - 1][j] = 2;
						flag = 1;
					}
					if (j != size - 1 && b[i][j + 1] == 0) {
						a[i][j + 1] = 2;
						flag = 1;
					}
					if (j != 0 && b[i][j - 1] == 0) {
						a[i][j - 1] = 2;
						flag = 1;
					}
					if (i != size - 1 && b[i + 1][j] == 0) {
						a[i + 1][j] = 2;
						flag = 1;
					}
				}
			}
		}
	}

	printf("%d\n", Time);
	return 0;

}