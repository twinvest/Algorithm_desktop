#include <cstdio>
#include<algorithm>
using namespace std;
int main() {
	int m[200000];
	int N, C;
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; i++)
		scanf("%d", m + i);
	sort(m, m + N);
	int lo = 1, hi = 1000000000;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;//현재 탐색중인 최대 거리
		int d = m[0];//1번집에는 무조껀 설치
		int cnt = 1;//설치한 공유기 개수 카운팅
		for (int i = 1; i < N; i++) {
			if (mid + d <= m[i]) {//만약 설치가 가능하다면
				d = m[i];//설치하고 위치 저장
				cnt++;//거리 카운팅
			}
		}
		if (cnt >= C) lo = mid + 1;//설치할 수 있는갯수가 C보다 크면 하한 증가
		else hi = mid - 1; //아니면 상한 감소
	}
	printf("%d", hi);
}