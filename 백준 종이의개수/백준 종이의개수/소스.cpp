#include<cstdio>
#include<iostream>
int flag0, flag1, flag2, N = 0;
int arr[2187][2187];
void search(int y, int x, int size)
{
	bool flag = true;
	int base = arr[y][x];
	for (int i = y; i < size + y; i++)
		for (int j = x; j < size + x; j++)
			if (base != arr[i][j])
				flag = false;
	if (flag){
		if (base == -1)	flag0++;
		else if (base == 0) flag1++;
		else flag2++;
	}
	else {
		for(int i=y; i<size+y; i += (size/3))
			for (int j = x; j<size+x; j += (size / 3))
				search(i, j, size / 3);
	}
}
int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	search(0, 0, N);
	printf("%d\n", flag0); printf("%d\n", flag1); printf("%d\n", flag2);
}