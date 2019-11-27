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
	Activity A[MAX_ARRAY_SIZE]; //A�� �Է¹������� activity
	//Activity WASP[MAX_ARRAY_SIZE];
	int Weight_sum[MAX_ARRAY_SIZE] = { 0 };
	int Weight_result;
	int N;
	int F;
	int i = 0, j = 0;

	//�Է� �ޱ�. ���� A���ٰ� �Է� �޽��ϴ�.
	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		A[i].id = i;
		scanf("%d %d %d", &A[i].start, &A[i].finish, &A[i].weight);
	}

	//finish�� �������� ���ĸ��� ����
	ActivitySort(A, N);

	//Weight_sum[i]�� ���ĵ� Activity�� i��° ������ ����ġ ��.
	//BASE���̽� ù��° activity�� �ʱ�ȭ�ϰ� �����
	Weight_sum[0] = A[0].weight;
	Weight_result = Weight_sum[0];
	
	for (i = 1; i < N; i++) {
		for (j = i - 1; j >= 0; j--) {
			//���� i��° �������� 1, 2, ..., i-1�� ���Ͽ� �߰��� �� �ִ� activity�� ����ġ�� ���� �� ����.
			if ((A[i].start >= A[j].finish) && (Weight_sum[i] < Weight_sum[j])) {
				Weight_sum[i] = Weight_sum[j] + A[i].weight;
				//if (Weight_sum[i] > Weight_result) {
				//	Weight_result = Weight_sum[i];
				//}
			}
		}
	}
	for (int i = 0; i < N; i++)
		printf("%d��° activity������ ������ : %d\n", i+1, Weight_sum[i]);
	//printf("%d\n", Weight_result);
		
	
	
	
	////�������� ���� Activity Ž��.
	//int S = 99999; //�������� �ʿ��� start�� ���� ���� ���Ѵ�� �ʱ�ȭ
	//int k = 0; //��� Activity�κ������� index�ʱ�ȭ

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
