#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int W, H;
int S[50][50], visited[50][50];
int dir[8][2] = { { -1,0 },{ 1,0 },{ 0,1 },{ 0,-1 },{ 1,1 },{ -1,-1 },{ -1,1 },{ 1,-1 } };
bool inside(int n, int m) {
	return (n >= 0 && n < H) && (m >= 0 && m < W);
}
void dfs(int n, int m) {
	visited[n][m] = 1;
	if (S[n][m] == 0) return;
	for (int i = 0; i < 8; i++)
		if (inside(n + dir[i][0], m + dir[i][1]) && !visited[n + dir[i][0]][m + dir[i][1]])
			dfs(n + dir[i][0], m + dir[i][1]);
}
int main() {
	while (true) {
		int sum = 0;
		scanf("%d %d", &W, &H);
		if (W == 0 && H == 0) break;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) scanf("%d", &S[i][j]);
		for (int i = 0; i < H; i++) fill(visited[i], visited[i] + W, 0);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (S[i][j] == 1 && !visited[i][j]) {
					dfs(i, j);
					sum++;
				}
			}
		}
		printf("%d\n", sum);
	}
}