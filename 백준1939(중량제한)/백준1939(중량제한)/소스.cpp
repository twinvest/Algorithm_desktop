#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_V = 10001;
typedef pair<int, int> P;
int N, M, S, E;
vector<P> adj[MAX_V];
bool visited[MAX_V];
bool dfs(int curr, int W) {//그래프 탐색
	if (curr == E) return true;
	visited[curr] = true;
	for (auto P : adj[curr]) {
		int next = P.first, C = P.second;
		//아직 방문하지 않았고, 현재 한계보다 C가 크면 dfs
		if (!visited[next] && C >= W && dfs(next, W)) return true;//dfs가 true를 반환하면 true 반환
	}
	return false;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);//양방향 간선 추가
		adj[u].emplace_back(P{ v,w });
		adj[v].emplace_back(P{ u,w });
	}
	scanf("%d%d", &S, &E);
	int lo = 0, hi = 1e9;//Prametric search
	while (lo <= hi) {
		int mid = (lo + hi) / 2;//현재 한계값으로 지정
		if (dfs(S, mid)) lo = mid + 1;//현재 한계값으로 도달할 수 있다면
		else hi = mid - 1;//아니라면
		fill(visited, visited + MAX_V, false);//방문 배열 초기화
	}
	printf("%d", hi);//출력
}