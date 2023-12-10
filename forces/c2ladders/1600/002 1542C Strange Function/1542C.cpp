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
		long long req = 1;
		long long trait = 1;
		for (long long i = 2; n > 0; ++i) {
			req = i/(__gcd(trait,i));
			trait *= req;
			// printf("%lld req\n",req);
			long long survive = n/req;
			ans += (i*((n-survive)%mod));
			ans %= mod;
			n = survive;
		}
		printf("%lld\n",ans);
	}
	return 0;
}