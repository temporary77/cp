#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
long long fac[200001];

int main() {
	fac[0] = 1;
	for (int i = 1; i <= 200000; ++i) {
		fac[i] = fac[i-1]*i;
		fac[i] %= mod;
	}
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int cur = INT_MAX;
		int prev = -1;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			cur &= a;
			if (a == cur) {
				if (a != prev) {
					prev = a;
					cnt = 0;
				}
				++cnt;
			}
			if (cur != prev) {
				cnt = 0;
			}
		}
		long long ans = (long long)cnt*(cnt-1);
		ans %= mod;
		ans *= fac[n-2];
		ans %= mod;
		printf("%lld\n",ans);
	}
	return 0;
}