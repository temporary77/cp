#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m;
	int q;
	scanf("%lld%lld%d",&n,&m,&q);
	long long a = n, b = m;
	if (a < b)swap(a,b);
	for (;;) {
		a %= b;
		swap(a,b);
		if (b == 0)break;
	}
	long long gcd = a;
	long long nroom = n/gcd;
	long long mroom = m/gcd;
	for (int i = 0; i < q; ++i) {
		int sx, sy;
		long long x, y;
		scanf("%d%lld%d%lld",&sx,&x,&sy,&y);
		--x; --y;
		long long rx, ry;
		if (sx == 1) {
			rx = x/nroom;
		} else if (sx == 2) {
			rx = x/mroom;
		}
		if (sy == 1) {
			ry = y/nroom;
		} else if (sy == 2) {
			ry = y/mroom;
		}
		if (rx == ry) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}