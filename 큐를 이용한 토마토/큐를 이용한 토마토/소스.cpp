#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
#define MAX 1000
int S[MAX][MAX];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,1 },{ 0,-1 } }; //위 밑 오른쪽 왼쪽
int count;
int N, M;
bool inside(int m, int n) {
	return (n >= 0 && n < N) && (m >= 0 && m < M);
}
queue<P> Q;
int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &S[i][j]);

	for (int i = 0; i < N; i++) {      //1이면 전부 큐에 집어 넣음.
		for (int j = 0; j < M; j++) {
			if (S[i][j] == 1)
				Q.push({ i, j });
		}
	}
	while (!Q.empty()) {
		auto now = Q.front();
		Q.pop();
		int y = now.first, x = now.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (!inside(nx, ny)) continue;
			if (S[ny][nx] == 0) {
				S[ny][nx] = S[y][x] + 1;
				Q.push({ ny,nx });
			}
		}
	}
	int result = -2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!S[i][j]) return !printf("-1");;
			result = max(result, S[i][j]);
		}
	}
	printf("%d", result - 1);
	return 0;
}