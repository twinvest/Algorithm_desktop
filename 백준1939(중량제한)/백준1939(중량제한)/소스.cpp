#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_V = 10001;
typedef pair<int, int> P;
int N, M, S, E;
vector<P> adj[MAX_V];
bool visited[MAX_V];
bool dfs(int curr, int W) {//�׷��� Ž��
	if (curr == E) return true;
	visited[curr] = true;
	for (auto P : adj[curr]) {
		int next = P.first, C = P.second;
		//���� �湮���� �ʾҰ�, ���� �Ѱ躸�� C�� ũ�� dfs
		if (!visited[next] && C >= W && dfs(next, W)) return true;//dfs�� true�� ��ȯ�ϸ� true ��ȯ
	}
	return false;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);//����� ���� �߰�
		adj[u].emplace_back(P{ v,w });
		adj[v].emplace_back(P{ u,w });
	}
	scanf("%d%d", &S, &E);
	int lo = 0, hi = 1e9;//Prametric search
	while (lo <= hi) {
		int mid = (lo + hi) / 2;//���� �Ѱ谪���� ����
		if (dfs(S, mid)) lo = mid + 1;//���� �Ѱ谪���� ������ �� �ִٸ�
		else hi = mid - 1;//�ƴ϶��
		fill(visited, visited + MAX_V, false);//�湮 �迭 �ʱ�ȭ
	}
	printf("%d", hi);//���
}