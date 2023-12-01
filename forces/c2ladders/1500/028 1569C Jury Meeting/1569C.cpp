#include <bits/stdc++.h>
using namespace std;

long long fac[200001];
const int mod = 998244353;

long long modinverse(long long x) {
	long long res = 1;
	int n = mod-2;
	for (;n > 0;) {
		if (n&1) {
			res *= x;
			res %= mod;
		}
		x *= x;
		x %= mod;
		n >>= 1;
	}
	return res;
}

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
		int max1[2] = {INT_MIN,INT_MIN};
		int cnt[2] = {0,0};
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			if (a >= max1[0]) {
				if (a == max1[0]) {
					++cnt[0];
				} else {
					max1[1] = max1[0];
					cnt[1] = cnt[0];
					max1[0] = a;
					cnt[0] = 1;
				}
			} else if (a >= max1[1]) {
				if (a == max1[1]) {
					++cnt[1];
				} else {
					max1[1] = a;
					cnt[1] = 1;
				}
			}
		}
		// printf("%d %d\n",cnt[0],cnt[1]);
		if (cnt[0] > 1) {
			printf("%lld\n",fac[n]);
		} else if (max1[0]-max1[1] >= 2) {
			printf("0\n");
		} else {
			printf("%lld\n",(((fac[n]*cnt[1])%mod)*modinverse(cnt[1]+1))%mod);
		}
	}
	return 0;
}