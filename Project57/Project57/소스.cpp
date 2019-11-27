#include <cstdio>
#include <algorithm>
using namespace std;
int N, S[100001], cnt;
bool visited[100001], finished[100001];
void dfs(int curr) {
	visited[curr] = true;
	int next = S[curr];
	if (visited[next]) {
		if (!finished[next]) {
			for (int temp = next; temp != curr; temp = S[temp]) cnt++;
			cnt++;
		}
	}
	else dfs(next);
	finished[curr] = true;
}
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", S + i);
		}
		fill(visited + 1, visited + N + 1, false);
		fill(finished + 1, finished + N + 1, false);
		cnt = 0;
		for (int i = 1; i <= N; i++)
			if (!visited[i]) dfs(i);
		printf("%d\n", N - cnt);
	}
}