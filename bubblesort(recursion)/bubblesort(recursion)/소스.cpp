#include<cstdio>
int swap(int arr[])
{
	int temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	return 0;
}
//n개의 정수가 있는 배열에서 가장 큰 값을 맨 마지막으로 보낸다.
int bubble(int arr[], int n)
{
	//맨 앞 2개를 비교하고, 앞에 것이 크면 서로 바꾸고, 나머지에 대해서도 반복함.
	(1 < n) && (((arr[0] > arr[1]) && swap(arr)) || bubble(arr + 1, n - 1));//오름차순정렬
	return 1;
}
int sort(int arr[], int n) //n개의 정수가 있는 배열을 정렬함.
{
	//가장 큰 것을 맨 마지막으로 보냄. 그리고 그 앞에 있는 n-1개를 같은 방식으로 정렬함.
	(1 < n) && bubble(arr, n) && sort(arr, n - 1);
	return 1;
}
int main()
{
	int A[] = { 5,3,2,1,6,1 };
	sort(A, 6);
	for (int i = 0; i < 6; i++)
		printf("%d", A[i]);
}