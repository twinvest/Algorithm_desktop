#include<stdio.h>
void Swap(int arr[], int arr2[], int a, int b) // a,b 스왑 함수 
{
	int temp = arr[a];
	int temp2 = arr2[a];   //자리를 교환할 때 p2도 그대로 같이 교환해준다.
	
	arr[a] = arr[b];
	arr2[a] = arr2[b];    //자리를 교환할 때 p2도 그대로 같이 교환해준다.
	
	arr[b] = temp;
	arr2[b] = temp2;       //자리를 교환할 때 p2도 그대로 같이 교환해준다.
}
int Partition(int arr[], int arr2[], int left, int right)
{
	int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽에서 시작
	int low = left + 1;
	int high = right;

	while (low <= high) // 교차되기 전까지 반복한다 
	{
		while (pivot >= arr[low] && low <= right) // 피벗보다 큰 값을 찾는 과정 
		{
			low++; // low를 오른쪽으로 이동 
		}
		while (pivot <= arr[high] && high >= (left + 1)) // 피벗보다 작은 값을 찾는 과정 
		{
			high--; // high를 왼쪽으로 이동
		}
		if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행 
		{
			Swap(arr, arr2, low, high); //low와 high를 스왑 
		}
	}
	Swap(arr, arr2, left, high); // 피벗과 high가 가리키는 대상을 교환 
	return high;  // 옮겨진 피벗의 위치정보를 반환 

}

void QuickSort(int arr[], int arr2[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, arr2, left, right); // 둘로 나누어서
		QuickSort(arr, arr2, left, pivot - 1); // 왼쪽 영역을 정렬한다.
		QuickSort(arr, arr2, pivot + 1, right); // 오른쪽 영역을 정렬한다.
	}
}


int main()
{
	int test_case;
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		int ufo_num;             //우주선 개수
		int missile_kind_num;    //미사일 종류 수
		int ufo_shield;          //우주선 방어막 세기
		scanf("%d", &ufo_num);
		scanf("%d", &missile_kind_num);
		scanf("%d", &ufo_shield);

		int * p1 = (int*)malloc(sizeof(int)*missile_kind_num);    //미사일의 위력을 저장할 p1
		int * p2 = (int*)malloc(sizeof(int)*missile_kind_num);    //미사일의 개수를 저장할 p2

		for (int j = 0; j < missile_kind_num; j++) //p1과 p2에 저장
		{
			scanf("%d", &p1[j]);
			scanf("%d", &p2[j]);
		}
		
		QuickSort(p1, p2, 0, missile_kind_num - 1); //여기까지 p1과 p2 정렬완료!!
		
		while (ufo_num) //여기서 부턴 격파하는 알고리즘.
		{
			int i = 0; //배열 인덱스로 쓸 i
			int j = 1; //사용할 미사일로 쓸 j
			
			if (p2[i] == 0) //만약 p2의 미사일 개수가 0개인경우. 이 경우에는 미사일 사용불가. 따라서 i값 하나 올려서 다음 미사일 준비.
				i++;
			else            //미사일의 개수가 0이 아닌 경우에는 제일 작은것부터 사용해서 격파 가능한지 확인해봄.
			{
				if ((p1[i] * j) > ufo_shield)  //첫번째 경우. 내가 가진 미사일 중에 가장 약한 미사일 한개로 격파 가능한 경우.
				{
					ufo_num--;  //ufo의 숫자를 줄이고
					p2[i]--;    //내가 사용한 미사일의 숫자를 줄인다.
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