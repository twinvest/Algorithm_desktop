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
void selection(int arr[], int n)//�ݺ������� ġ�� ���� ����
{
	if (size == n) return;
	if (arr[0] > p[n]) swap(&arr[0], &p[n]); //����, �������� ������ �ȵ� �ִ� ���� �߰ߵǸ� swap!
	selection(arr, n + 1);	 //ù��°�� ���� �ε����� ���ϱ� ���� ���.
}
void sort(int arr[], int n) //�ݺ������� ġ�� ū ����
{
	if (size == n) return;
	else {
		selection(arr + n, n); //ù��° �ε����� �������� selection����.
		sort(arr, n + 1); //����, ù��° �ڸ��� �����ǰ� ���� �ι�° �ڸ��� �����Ϸ� �ٽ� sort!
	}
}
int main() 
{
	sort(arr, 0);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}