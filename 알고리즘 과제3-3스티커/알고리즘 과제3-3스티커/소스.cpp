#include<cstdio>
#define MAX(a,b) (a>b) ? a:b

int sticker[2][100001]; //��ƼĿ �迭
int dp[2][100001];      //DP�迭
int main() {
	int T, n;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &sticker[i][j]);  //��ƼĿ ������ �Է¹���.
			}
		}
		dp[0][1] = sticker[0][1]; dp[1][1] = sticker[1][1];  //BASE CASE. ��, ó������ �̰� ����� ���� ����.
		for (int i = 2; i <= n; i++) { //DP�迭�� ä������ ��ȭ��
			//�밢�� ����� �밢�� ������ ����ĭ �� �� ��ū ���� ���� ��ƼĿ ���� ���ؼ� DP�迭�� �ʱ�ȭ
			dp[0][i] = MAX(dp[1][i - 1] + sticker[0][i], dp[1][i - 2] + sticker[0][i]);
			dp[1][i] = MAX(dp[0][i - 1] + sticker[1][i], dp[0][i - 2] + sticker[1][i]);
		}
		printf("%d\n", MAX(dp[1][n], dp[0][n])); //���� ������ ���� ����� �Ʒ��� �� �� ū ���� ��ȯ.
	}
}
