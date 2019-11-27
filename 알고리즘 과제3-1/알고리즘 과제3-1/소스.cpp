#include <cstdio>
using namespace std;
int ans;
void rec(int cur)
{
	if (cur < 0)return;
	if (cur == 0) {
		++ans;
		return;
	}
	for (int i = 1; i <= 3; ++i)
		rec(cur - i);
}
int main()
{
	int x;
	ans = 0;
	scanf("%d", &x);
	rec(x);
	printf("%d", ans);
}