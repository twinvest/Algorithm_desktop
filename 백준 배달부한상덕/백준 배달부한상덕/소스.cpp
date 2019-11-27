#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;
typedef pair< int, int> P;
priority_queue<int> pq;
#define MAX 50
int arr[MAX][MAX];
char str[MAX][MAX];
int rel[8][2] = { { 0,1 },{ 0,-1 },{ -1,0 },{ 1,0 },{ 1,1 },{ -1,-1 },{ -1,1 },{ 1,-1 } };

int N;
bool inside(int m, int n) {
	return (n >= 0 && n < N) && (m >= 0 && m < N);
}
queue<P> Q;
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%s", str[i]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf_s("%d", &arr[i][j]);

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (str[i][j] == 'P')
			{
				Q.push({ i, j });
				pq.push(arr[i][j]);
				arr[i][j] = -1;
			}
		}
	}
	while (!Q.empty()) //확장해가는 과정.
	{
		auto now = Q.front();
		Q.pop();
		int y = now.first, x = now.second;
		
		for (int i = 0; i < 8; i++)
		{
			int ny = y + rel[i][0], nx = x + rel[i][1];
			if (!inside(ny, nx)) continue; //범위를 벗어나면 다시 for문으로.
			if(arr[ny][nx] != -1) //방문할 곳에 대한 쿵짝쿵짝.
			{
				Q.push({ ny,nx });
				pq.push(arr[ny][nx]);
				arr[ny][nx] = -1;
			}
		}
	}
	
	while (!pq.empty())
	{
		printf("%d", pq.top());
		pq.pop();
	}
	
	return 0;
}
