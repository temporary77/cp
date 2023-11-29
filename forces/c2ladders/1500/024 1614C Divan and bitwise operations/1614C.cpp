#include <bits/stdc++.h>
using namespace std;

long long pow2[200001];
const int mod = 1e9+7;

int main() {
	pow2[0] = 1;
	for (int i = 1; i <= 200000; ++i) {
		pow2[i] = pow2[i-1]*2;
		pow2[i] %= mod;
	}
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		scanf("%d%d",&n,&m);
		int sumor = 0;
		for (int i = 0; i < m; ++i) {
			int x;
			scanf("%*d%*d%d",&x);
			sumor |= x;
		}
		long long ans = 0;
		for (int i = 0; i < 30; ++i) {
			if (sumor&(1 << i)) {
				ans += (1 << i)*pow2[n-1];
				ans %= mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}