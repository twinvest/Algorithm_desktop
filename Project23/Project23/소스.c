#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int arr[][100], int n);

int main() {
	int num, i, j;
	int arr[100][100];
	printf("정렬할 배열의 size를 입력하세요");
	scanf("%d", &num);

	for (i = 0; i<num; i++) {
		for (j = 0; j<num; j++) {
			arr[i][j] = rand() % 10;
		}
	}
	BubbleSort(arr, num);
	for (i = 0; i<num; i++) {
		for (j = 0; j<num; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void BubbleSort(int arr[][100], int n) {
	int i, j;
	int temp;
	for (i = 0; i<n*n; i++) {
		for (j = i + 1; j<n*n; j++) {
			if (arr[i / n][i%n] > arr[j / n][j%n]) {
				temp = arr[i / n][i%n];
				arr[i / n][i%n] = arr[j / n][j%n];
				arr[j / n][j%n] = temp;
			}
		}
	}

	for (i = 0; i<n*n; i++) {
		for (j = i + 1; j<n*n; j++) {
			if ((arr[i / n][i%n] < arr[j / n][j%n]) && i / n == j / n && (i / n) % 2 == 1) {
				temp = arr[i / n][i%n];
				arr[i / n][i%n] = arr[j / n][j%n];
				arr[j / n][j%n] = temp;
			}
		}
	}

}
