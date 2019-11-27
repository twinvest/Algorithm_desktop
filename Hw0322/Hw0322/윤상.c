#include <stdio.h>
#include <stdlib.h>
void main() {
	int size;
	int **arr;
	int i, j, k, l;
	int a, b;
	int temp;

	scanf_s("%d", &size);
	arr = (int**)malloc(sizeof(int*)*size);


	for (i = 0; i < size; i++)
		arr[i] = (int*)malloc(sizeof(int)*size);
	for (i = 0; i < size; i++) 
	{
		for (j = 0; j < size; j++) 
		{
			arr[i][j] = rand() % 100;
		}
	}


	for (i = 0; i < size; i++) 
	{
		for (j = 0; j < size; j++) 
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	for (l = 0; l < size; l++) 
	{
		for (k = 0; k < size; k++) 
		{
			a = l;
			b = k + 1;
			if (k == size - 1 && l < size - 1)
				a = l + 1;
			for (i = a; i < size; i++)
			{
				if (i > l)
					b = 0;
				for (j = b; j < size; j++) {
					if (arr[l][k] > arr[i][j]) {
						temp = arr[i][j];
						arr[i][j] = arr[l][k];
						arr[l][k] = temp;
					}
				}
			}
		}
	}
	for (i = 0; i < size; i++) 
	{
		for (j = 0; j < size; j++) 
		{
			for (k = j + 1; k < size; k++) 
			{
				if (i % 2 != 0) {
					if (arr[i][j] < arr[i][k]) 
					{
						temp = arr[i][j];
						arr[i][j] = arr[i][k];
						arr[i][k] = temp;
					}
				}
			}
		}
	}
	for (i = 0; i < size; i++) 
	{
		for (j = 0; j < size; j++) 
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}