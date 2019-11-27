#include<stdio.h>
void Swap(int arr[], int arr2[], int a, int b) // a,b ���� �Լ� 
{
	int temp = arr[a];
	int temp2 = arr2[a];   //�ڸ��� ��ȯ�� �� p2�� �״�� ���� ��ȯ���ش�.
	
	arr[a] = arr[b];
	arr2[a] = arr2[b];    //�ڸ��� ��ȯ�� �� p2�� �״�� ���� ��ȯ���ش�.
	
	arr[b] = temp;
	arr2[b] = temp2;       //�ڸ��� ��ȯ�� �� p2�� �״�� ���� ��ȯ���ش�.
}
int Partition(int arr[], int arr2[], int left, int right)
{
	int pivot = arr[left]; // �ǹ��� ��ġ�� ���� ���ʿ��� ����
	int low = left + 1;
	int high = right;

	while (low <= high) // �����Ǳ� ������ �ݺ��Ѵ� 
	{
		while (pivot >= arr[low] && low <= right) // �ǹ����� ū ���� ã�� ���� 
		{
			low++; // low�� ���������� �̵� 
		}
		while (pivot <= arr[high] && high >= (left + 1)) // �ǹ����� ���� ���� ã�� ���� 
		{
			high--; // high�� �������� �̵�
		}
		if (low <= high)// �������� ���� �����̸� ���� ���� ���� 
		{
			Swap(arr, arr2, low, high); //low�� high�� ���� 
		}
	}
	Swap(arr, arr2, left, high); // �ǹ��� high�� ����Ű�� ����� ��ȯ 
	return high;  // �Ű��� �ǹ��� ��ġ������ ��ȯ 

}

void QuickSort(int arr[], int arr2[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, arr2, left, right); // �ѷ� �����
		QuickSort(arr, arr2, left, pivot - 1); // ���� ������ �����Ѵ�.
		QuickSort(arr, arr2, pivot + 1, right); // ������ ������ �����Ѵ�.
	}
}


int main()
{
	int test_case;
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		int ufo_num;             //���ּ� ����
		int missile_kind_num;    //�̻��� ���� ��
		int ufo_shield;          //���ּ� �� ����
		scanf("%d", &ufo_num);
		scanf("%d", &missile_kind_num);
		scanf("%d", &ufo_shield);

		int * p1 = (int*)malloc(sizeof(int)*missile_kind_num);    //�̻����� ������ ������ p1
		int * p2 = (int*)malloc(sizeof(int)*missile_kind_num);    //�̻����� ������ ������ p2

		for (int j = 0; j < missile_kind_num; j++) //p1�� p2�� ����
		{
			scanf("%d", &p1[j]);
			scanf("%d", &p2[j]);
		}
		
		QuickSort(p1, p2, 0, missile_kind_num - 1); //������� p1�� p2 ���ĿϷ�!!
		
		while (ufo_num) //���⼭ ���� �����ϴ� �˰���.
		{
			int i = 0; //�迭 �ε����� �� i
			int j = 1; //����� �̻��Ϸ� �� j
			
			if (p2[i] == 0) //���� p2�� �̻��� ������ 0���ΰ��. �� ��쿡�� �̻��� ���Ұ�. ���� i�� �ϳ� �÷��� ���� �̻��� �غ�.
				i++;
			else            //�̻����� ������ 0�� �ƴ� ��쿡�� ���� �����ͺ��� ����ؼ� ���� �������� Ȯ���غ�.
			{
				if ((p1[i] * j) > ufo_shield)  //ù��° ���. ���� ���� �̻��� �߿� ���� ���� �̻��� �Ѱ��� ���� ������ ���.
				{
					ufo_num--;  //ufo�� ���ڸ� ���̰�
					p2[i]--;    //���� ����� �̻����� ���ڸ� ���δ�.
				}
				else if
				{

				}

			}

		}





		/*for (int j = 0; j < missile_kind_num; j++) 
		{
			printf("%d ", p1[j]);
			printf("%d\n", p2[j]);
		}*/
			
			
	}
}