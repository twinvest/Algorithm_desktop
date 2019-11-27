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
	//���������� �� ���ų� ������ �� ���� ���
	for (int i = 1; i<N; i++)
	{
		cheese_cnt[0][i] = cheese_cnt[0][i] + cheese_cnt[0][i - 1];
		cheese_cnt[i][0] = cheese_cnt[i][0] + cheese_cnt[i - 1][0];
	}
	//ġ��[i][j]�� ���� �� ��ġ�� �ִ� ġ�� ����(0�ƴϸ� 1)���ٰ� �������κ��� �� �Ǵ� �������κ��� �� ġ���� ���� �� �� ū ���� ���ذ���. 
	//�׷� ��ħ�� ġ�� �迭��[N][N] ������ ��λ� ���� �ִ� �ִ� ġ���� ������ �� ���� ���̴�!!
	for (int i = 1; i<N; i++)
		for (int j = 1; j<N; j++)
			cheese_cnt[i][j] = cheese_cnt[i][j] + (cheese_cnt[i - 1][j] >= cheese_cnt[i][j - 1]) ? cheese_cnt[i - 1][j] : cheese_cnt[i][j - 1]; 

	printf("%d", cheese_cnt[N - 1][N - 1]);
	return 0;
}