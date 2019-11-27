#include <cstdio>
#include <algorithm>
using namespace std;
int A[65][65];
void quadtree(int x, int y, int size) 
{
	bool complete = true;
	int tmp = A[y][x];
	for (int i = y; i < y + size; i++) //하나씩 다 검사
		for (int j = x; j < x + size; j++)
			if (tmp != A[i][j]) 
				complete = false;
	
	if (complete) //플래그가 한번도 안바꼈으면 바로 출력해줌.
		printf("%d", A[y][x]);
	else          //바꼈으면 재귀 호출
	{
		printf("(");
		for (int i = y; i < y + size; i += (size / 2))
			for (int j = x; j < x + size; j += (size / 2))
				quadtree(j, i, size / 2);
		printf(")");
	}
}
int main() 
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			scanf("%1d", &A[i][j]);
	quadtree(0, 0, N);
}