#include <iostream>
#include<cstdio>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int w = 0, h = 0;
	int result = N - 1;
	for (int i = 1; i < N; i++)
	{
		if (N%i == 0)
			if (abs(N / i) - i < result)
				result = abs(N / i) - i;
	}
	printf("%d", result);
	return 0;
}