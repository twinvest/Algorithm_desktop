#include<cstdio>
int size = 5;
int recursion(int arr[], int n, int sum)
{
	sum += arr[n];
	if (n == size-1) return sum;
	else return recursion(arr, n + 1, sum);
}

int main()
{
	int arr[5] = { 2, 3, 1, 4, 10 };
	int sum = recursion(arr, 0, 0);
	printf("%d\n", sum);
}