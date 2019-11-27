#include <cstdio>
int N, dp[100001][3], arr[100001][3];
/*
dp[i][0] : 아무것도 선택 x
dp[i][1] : 첫 번째꺼 선택
dp[i][2] : 두 번째꺼 선택
*/
int MAX(int a, int b) {
	return a > b ? a : b;
}

int MAX3(int a, int b, int c) {
	return MAX(a, MAX(b, c));
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		for (int i = 1; i <= N; ++i) { //배열 초기화
			for (int j = 0; j <= 2; ++j) {
				dp[i][j] = 0;
				arr[i][j] = 0;
			}
		}
		scanf("%d", &N);
		for (int i = 1; i <= 2; ++i) {      //스티커 값 입력부
			for (int j = 1; j <= N; ++j) {
				scanf("%d", &arr[j][i]);
			}
		}
		dp[1][0] = 0;                      //basecase
		dp[1][1] = arr[1][1];              //basecase
		dp[1][2] = arr[1][2];              //basecase
		for (int i = 2; i <= N; ++i) {
			dp[i][0] = MAX3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);  //i열에서 아무것도 선택하지 않은 경우
			dp[i][1] = MAX(dp[i - 1][2], dp[i - 1][0]) + arr[i][1];     //i열에서 1행을 선택한 경우
			dp[i][2] = MAX(dp[i - 1][1], dp[i - 1][0]) + arr[i][2];     //i열에서 2행을 선택한 경우
		}
		printf("%d\n", MAX3(dp[N][0], dp[N][1], dp[N][2])); //마지막 열의 가장 큰 행을 반환
	}
}
