#include<stdio.h>
int arr[246913];
int main()
{
	arr[1] = arr[0] = 1;
	for (int i = 2; i < 246913; i++)//2�� ���. 3�� ���. .......246913�� ��� ��� 1�� ��������. ��, �Ҽ��� ���Եȴ�.(0�� �Ҽ�)
	{
		if (!arr[i])
		{
			for (int j = i + i; j < 246913; j = j + i)
				arr[j] = 1;
		}
	}
	while (1)
	{
		int N, cnt = 0;
		scanf("%d", &N); //�Է¹��� �� N
		if (!N)
		{
			break;
		}
		for (int i = N + 1; i <= 2 * N; i++)//N���ٴ� ũ�� 2N���ٴ� �۰ų� ���� �Ҽ��� ���� ���~~����.
		{
			if (!arr[i]) //0�ΰŴ� ��� �Ҽ��ϱ� 1�� �ٲ㼭 cnt�� �÷���.
				cnt++;
		}
		printf("%d\n", cnt);
	}
}