#include<cstdio>
int swap(int arr[])
{
	int temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	return 0;
}
//n���� ������ �ִ� �迭���� ���� ū ���� �� ���������� ������.
int bubble(int arr[], int n)
{
	//�� �� 2���� ���ϰ�, �տ� ���� ũ�� ���� �ٲٰ�, �������� ���ؼ��� �ݺ���.
	(1 < n) && (((arr[0] > arr[1]) && swap(arr)) || bubble(arr + 1, n - 1));//������������
	return 1;
}
int sort(int arr[], int n) //n���� ������ �ִ� �迭�� ������.
{
	//���� ū ���� �� ���������� ����. �׸��� �� �տ� �ִ� n-1���� ���� ������� ������.
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