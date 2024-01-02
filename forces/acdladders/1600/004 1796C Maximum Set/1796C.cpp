#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int l, r;
		scanf("%d%d",&l,&r);
		int x = l;
		int twos = 0;
		for (;x*2 <= r;) {
			++twos;
			x *= 2;
		}
		int k = x/l;
		long long ans = (r/k)-l+1;
		if (x >= l*2 && x*3/2 <= r) {
			k *= 3;
			k /= 2;
			ans += twos*(long long)((r/k)-l+1);
		}
		printf("%d %lld\n",twos+1,ans%mod);
	}
	return 0;
}