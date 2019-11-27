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
		int mid = (lo + hi) / 2;//���� Ž������ �ִ� �Ÿ�
		int d = m[0];//1�������� ������ ��ġ
		int cnt = 1;//��ġ�� ������ ���� ī����
		for (int i = 1; i < N; i++) {
			if (mid + d <= m[i]) {//���� ��ġ�� �����ϴٸ�
				d = m[i];//��ġ�ϰ� ��ġ ����
				cnt++;//�Ÿ� ī����
			}
		}
		if (cnt >= C) lo = mid + 1;//��ġ�� �� �ִ°����� C���� ũ�� ���� ����
		else hi = mid - 1; //�ƴϸ� ���� ����
	}
	printf("%d", hi);
}