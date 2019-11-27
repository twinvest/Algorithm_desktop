#include<cstdio>
#include<iostream>
int flag0 = 0;
int flag1 = 0;
void divide(int arr[][64], int col, int row, int left, int right, int point)
{
	printf("(");
	point /= 2;
	int mid1 = (col + row) / 2;
	int mid2 = (left + right) / 2;

	flag0 = 0;
	flag1 = 0;
	for (int i = col; i < mid1; i++) //1사분면0-4
	{
		for (int j = left; j < mid2; j++)//0-4
		{
			if (arr[i][j] == 0)
				flag0++;
			if (arr[i][j] == 1)
				flag1++;
		}
	}
	if (flag1 == point * point || flag0 == point * point)
	{
		if (flag1 == point * point)
			printf("1");
		if (flag0 == point * point)
			printf("0");
	}
	else
		divide(arr, col, mid1, left, mid2, point); //0404

	flag0 = 0;
	flag1 = 0;
	for (int i = col; i < mid1; i++) //2사분면0-4
	{
		for (int j = mid2; j < right; j++)//4-8
		{
			if (arr[i][j] == 0)
				flag0++;
			if (arr[i][j] == 1)
				flag1++;
		}
	}
	if (flag1 == point * point || flag0 == point * point)
	{
		if (flag1 == point * point)
			printf("1");
		if (flag0 == point * point)
			printf("0");
	}
	else
		divide(arr, col, mid1, mid2, right, point); //0448

	flag0 = 0;
	flag1 = 0;
	for (int i = mid1; i < row; i++)//3사분면4-8
	{
		for (int j = left; j < mid2; j++)//0-4
		{
			if (arr[i][j] == 0)
				flag0++;
			if (arr[i][j] == 1)
				flag1++;
		}
	}
	if (flag1 == point * point || flag0 == point * point)
	{
		if (flag1 == point * point)
			printf("1");
		if (flag0 == point * point)
			printf("0");
	}
	else
		divide(arr, mid1, row, left, mid2, point); //4804

	flag0 = 0;
	flag1 = 0;
	for (int i = mid1; i < row; i++)//4사분면4-8
	{
		for (int j = mid2; j < right; j++)//4-8
		{
			if (arr[i][j] == 0)
				flag0++;
			if (arr[i][j] == 1)
				flag1++;
		}
	}
	if (flag1 == point * point || flag0 == point * point)
	{
		if (flag1 == point * point)
			printf("1");
		if (flag0 == point * point)
			printf("0");
	}
	else
		divide(arr, mid1, row, mid2, right, point); //4848
	printf(")");
}
int main()
{
	int arr[64][64];
	int left = 0;
	int col = 0;
	int row;
	int right;
	scanf("%d", &right);
	row = right;
	int point = right;
	for (int i = 0; i < right; i++)
	{
		for (int j = 0; j < right; j++)
		{
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 1)
				flag1++;
			if (arr[i][j] == 0)
				flag0++;
		}
	}
	if (flag1 == point * point || flag0 == point * point)
	{
		if (flag1 == point * point)
			printf("1");
		if (flag0 == point * point)
			printf("0");
	}
	else
		divide(arr, col, row, left, right, point); //사실 이건 높이로 접근해야함.
}