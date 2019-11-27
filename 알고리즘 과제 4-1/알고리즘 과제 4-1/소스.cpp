#include <cstdio>
#define MAX_ARRAY_SIZE 100

typedef struct Activity {
	int id;
	int start;
	int finish;
	int weight;
}Activity;

void ActivitySort(Activity A[], int count) {

	int i = 0, j = 0;
	int min = 0;
	Activity temp;

	for (i = 0; i < count - 1; i++) {
		min = i;
		for (j = i + 1; j < count; j++) {
			if (A[j].finish < A[min].finish) {
				min = j;
			}
		}
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
}


int main() {
	Activity A[MAX_ARRAY_SIZE]; //A는 입력받을때의 activity
	//Activity WASP[MAX_ARRAY_SIZE];
	int Weight_sum[MAX_ARRAY_SIZE] = { 0 };
	int Weight_result;
	int N;
	int F;
	int i = 0, j = 0;

	//입력 받기. 최초 A에다가 입력 받습니다.
	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		A[i].id = i;
		scanf("%d %d %d", &A[i].start, &A[i].finish, &A[i].weight);
	}

	//finish를 기준으로 정렬먼저 실행
	ActivitySort(A, N);

	//Weight_sum[i]는 정렬된 Activity의 i번째 까지의 가중치 합.
	//BASE케이스 첫번째 activity는 초기화하고 가즈아
	Weight_sum[0] = A[0].weight;
	Weight_result = Weight_sum[0];
	
	for (i = 1; i < N; i++) {
		for (j = i - 1; j >= 0; j--) {
			//현재 i번째 기준으로 1, 2, ..., i-1에 대하여 추가할 수 있는 activity의 가중치를 더할 수 있음.
			if ((A[i].start >= A[j].finish) && (Weight_sum[i] < Weight_sum[j])) {
				Weight_sum[i] = Weight_sum[j] + A[i].weight;
				//if (Weight_sum[i] > Weight_result) {
				//	Weight_result = Weight_sum[i];
				//}
			}
		}
	}
	for (int i = 0; i < N; i++)
		printf("%d번째 activity까지의 최적해 : %d\n", i+1, Weight_sum[i]);
	//printf("%d\n", Weight_result);
		
	
	
	
	////역추적을 통한 Activity 탐색.
	//int S = 99999; //역추적에 필요한 start에 대한 변수 무한대로 초기화
	//int k = 0; //결과 Activity부분집합의 index초기화

	//for (i = N - 1; i >= 0; i--) {
	//	if ((Weight_result == Weight_sum[i]) && (S >= A[i].finish)) {
	//		Weight_result -= A[i].weight;
	//		S = A[i].start;
	//		WASP[k++] = A[i];
	//	}
	//}
	//for (int i = k - 1; i >= 0; i--)
	//	printf("Activity[%d] S: %d ~ F: %d \tW: %d\n", WASP[i].id, WASP[i].start, WASP[i].finish, WASP[i].weight);
	//return 0;
}
