#include <stdio.h>
#define MAX_ARRAY_SIZE 1000
#define exist_cheese 1
#define no_cheese 0
#pragma waring(disable:4996)
int main()
{
	//���� �����
	int N, M;
	int cheese_cnt[1000][1000];
	int cheese_x, cheese_y;

	//N,M �Էº�
	scanf("%d %d", &N, &M);

	//���� �ʱ�ȭ.
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j<N; j++)
			cheese_cnt[i][j] = no_cheese;
	}
		

	//ġ����ġ �Էº�
	for (int i = 0; i<M; i++)
	{
		scanf("%d %d", &cheese_x, &cheese_y);
		cheese_cnt[cheese_x - 1][cheese_y - 1] = exist_cheese;
	}

	//(1,i) Ȥ�� (i,1)�� �� ���
	for (int i = 1; i<N; i++)
	{
		cheese_cnt[0][i] += cheese_cnt[0][i - 1];
		cheese_cnt[i][0] += cheese_cnt[i - 1][0];
	}

	//����
	for (int i = 1; i<N; i++)
		for (int j = 1; j<N; j++)
			cheese_cnt[i][j] += cheese_cnt[i - 1][j] >= cheese_cnt[i][j - 1]
			? cheese_cnt[i - 1][j] : cheese_cnt[i][j - 1];
	printf("%d", cheese_cnt[N - 1][N - 1]);
	return 0;
}
