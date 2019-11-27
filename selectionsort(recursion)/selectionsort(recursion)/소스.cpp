#include<cstdio>
int arr[10] = { 10, 5, 1, 2, 6 ,4 , 9 , 20, 11, 7 };
int size = 10;
int * p = arr;
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int selection(int arr[], int n)
{
	if (size - 1 == n)
		return arr[0];
	else
	{
		if (arr[0] > arr[n + 1])
			swap(&arr[0], &arr[n + 1]);
		selection(arr, n + 1);
	}
}
int* sort(int arr[], int n)
{
	if (size-1 == n)
		return arr;
	else {
		p[n] = selection(arr + n, n);
		sort(arr, n + 1);
	}
	
}
int main()
{
	sort(arr, 0);
	for (int i = 0; i < 10; i++)
		printf("%d ", p[i]);
}