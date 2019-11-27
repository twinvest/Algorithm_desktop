#include<cstdio>
int arr[10] = { 2, 4, 10, 21, 3, 1, 5, 12, 7, 6 };
int size = 10;
int * p = arr;
void swap(int * a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void selection(int arr[], int n)//반복문으로 치면 작은 루프
{
	if (size == n) return;
	if (arr[0] > p[n]) swap(&arr[0], &p[n]); //만약, 오름차순 정렬이 안돼 있는 것이 발견되면 swap!
	selection(arr, n + 1);	 //첫번째와 다음 인덱스를 비교하기 위한 재귀.
}
void sort(int arr[], int n) //반복문으로 치면 큰 루프
{
	if (size == n) return;
	else {
		selection(arr + n, n); //첫번째 인덱스를 결정짓는 selection시작.
		sort(arr, n + 1); //만약, 첫번째 자리가 결정되고 오면 두번째 자리를 결정하러 다시 sort!
	}
}
int main() 
{
	sort(arr, 0);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}