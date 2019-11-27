#include<stdio.h>
int arr[246913];
int main()
{
	arr[1] = arr[0] = 1;
	for (int i = 2; i < 246913; i++)//2의 배수. 3의 배수. .......246913의 배수 모두 1로 만들어버림. 즉, 소수만 남게된다.(0이 소수)
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
		scanf("%d", &N); //입력받을 수 N
		if (!N)
		{
			break;
		}
		for (int i = N + 1; i <= 2 * N; i++)//N보다는 크고 2N보다는 작거나 같은 소수의 개수 출력~~조건.
		{
			if (!arr[i]) //0인거는 모두 소수니까 1로 바꿔서 cnt값 올려줌.
				cnt++;
		}
		printf("%d\n", cnt);
	}
}