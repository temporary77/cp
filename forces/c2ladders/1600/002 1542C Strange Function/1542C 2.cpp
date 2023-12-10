#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		long long n;
		scanf("%lld",&n);
		long long ans = 0;
		long long lcm = 1;
		long long corpses = 0;
		for (long long i = 2; corpses < n; ++i) {
			long long lcm1 = (lcm*i)/__gcd(lcm,i);
			long long die = (n/lcm)-(n/lcm1);
			// printf("> %lld\n",die);
			corpses += die;
			ans += i*die;
			ans %= mod;
			lcm = lcm1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}