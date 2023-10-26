#include "sum_product.h"
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

long long ans = 0;

int sum_product(int n, std::vector<int> a){
	long long cur = 1;
	for (int i = 0; i < n; ++i) {
		cur *= a[i];
		cur %= mod;
		if (i == n-1) {
			ans += cur%mod;
			ans %= mod;
			break;	
		}
		ans += (cur*((1 << n-2-i)%mod))%mod;
		ans %= mod;
		// printf("%lld\n",ans);
	}
	cur = 1;
	for (int i = n-1; i >= 1; --i) {
		cur *= a[i];
		cur %= mod;
		ans += (cur*((1 << i-1)%mod))%mod;
		ans %= mod;
		// printf("%lld\n",ans);
	}
	for (int i = 1; i < n-1; ++i) {
		cur = 1;
		int t = n-3;
		for (int j = i; j < n-1; ++j) {
			cur *= a[i];
			cur %= mod;
			// printf("%lld %d %lld<<\n",cur,(1 << t)%mod,cur*((1 << t)%mod)%mod);
			ans += (cur*((1 << t)%mod))%mod;
			// printf("%lld\n",ans);
			ans %= mod;
			// printf("%lld\n",ans);
			--t;
		}
	}
	return ans;
}
