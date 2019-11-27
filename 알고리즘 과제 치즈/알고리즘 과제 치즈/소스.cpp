#include<cstdio>
#define MAX_ARRAY_SIZE 10000
#define exist_cheese 1
#define no_cheese 0
int cheese_cnt[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
int main()
{
	int N, M;
	int x, y;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cheese_cnt[i][j] = no_cheese;
	
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		cheese_cnt[x - 1][y - 1] = exist_cheese;
	}
	//오른쪽으로 쭉 가거나 밑으로 쭉 가는 경우
	for (int i = 1; i<N; i++)
	{
		cheese_cnt[0][i] = cheese_cnt[0][i] + cheese_cnt[0][i - 1];
		cheese_cnt[i][0] = cheese_cnt[i][0] + cheese_cnt[i - 1][0];
	}
	//치즈[i][j]의 값은 그 위치에 있는 치즈 개수(0아니면 1)에다가 위쪽으로부터 온 또는 왼쪽으로부터 온 치즈의 개수 중 더 큰 값을 더해간다. 
	//그럼 마침내 치즈 배열의[N][N] 끝에는 경로상 얻을 있는 최대 치즈의 개수가 들어가 있을 것이다!!
	for (int i = 1; i<N; i++)
		for (int j = 1; j<N; j++)
			cheese_cnt[i][j] = cheese_cnt[i][j] + (cheese_cnt[i - 1][j] >= cheese_cnt[i][j - 1]) ? cheese_cnt[i - 1][j] : cheese_cnt[i][j - 1]; 

	printf("%d", cheese_cnt[N - 1][N - 1]);
	return 0;
}