#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector <pair<int, int>> P = { { 0,0 },{ 0,1 },{ 1,1 },{ 1,0 } };
void dnc(int n, int m, int x, int y, vector<int> order) {
	if (m <= 0 || m > n*n) return; //범위 제한
	if (n == 1) {
		printf("%d %d\n", x, y);
		return;
	}

	int nn = n / 2; 
	int k = nn * nn;
	dnc(nn, m, x + P[order[0]].first*nn, y + P[order[0]].second*nn, { order[0],order[3],order[2],order[1] });
	dnc(nn, m - k, x + P[order[1]].first*nn, y + P[order[1]].second*nn, order);
	dnc(nn, m - 2 * k, x + P[order[2]].first*nn, y + P[order[2]].second*nn, order);
	dnc(nn, m - 3 * k, x + P[order[3]].first*nn, y + P[order[3]].second*nn, { order[2],order[1],order[0],order[3] });
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> order = { 0,1,2,3 };
	dnc(n, m, 1, 1, order);
}
