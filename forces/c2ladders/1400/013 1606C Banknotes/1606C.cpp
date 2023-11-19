#include <bits/stdc++.h>
using namespace std;

int pow10[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		int prev;
		scanf("%d",&prev);
		long long ans = 0;
		++k;
		for (int i = 1; i < n; ++i) {
			int x;
			scanf("%d",&x);
			int slots = pow10[x-prev]-1;
			ans += (long long)min(slots,k)*pow10[prev];
			k -= min(slots,k);
			prev = x;
		}
		if (k) {
			ans += (long long)k*pow10[prev];
		}
		printf("%lld\n",ans);
	}
	return 0;
}