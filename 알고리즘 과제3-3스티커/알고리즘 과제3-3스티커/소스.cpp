#include<cstdio>
#define MAX(a,b) (a>b) ? a:b

int sticker[2][100001]; //스티커 배열
int dp[2][100001];      //DP배열
int main() {
	int T, n;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &sticker[i][j]);  //스티커 값들을 입력받음.
			}
		}
		dp[0][1] = sticker[0][1]; dp[1][1] = sticker[1][1];  //BASE CASE. 즉, 처음에는 이것 말고는 고를게 없음.
		for (int i = 2; i <= n; i++) { //DP배열을 채워가는 점화식
			//대각선 방향과 대각선 방향의 왼쪽칸 값 중 더큰 값에 현재 스티커 값을 더해서 DP배열을 초기화
			dp[0][i] = MAX(dp[1][i - 1] + sticker[0][i], dp[1][i - 2] + sticker[0][i]);
			dp[1][i] = MAX(dp[0][i - 1] + sticker[1][i], dp[0][i - 2] + sticker[1][i]);
		}
		printf("%d\n", MAX(dp[1][n], dp[0][n])); //가장 마지막 열의 윗행과 아랫행 중 더 큰 값을 반환.
	}
}
