#include  <cstdio>
using namespace std;
typedef long long ll;
ll A, B, V;
int main() {
	scanf("%lld%lld%lld", &A, &B, &V);
	ll lo = 0, hi = 1e9;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (V <= A * mid - B * (mid - 1)) hi = mid - 1;
		else lo = mid + 1;
	}
	printf("%lld", lo);
}