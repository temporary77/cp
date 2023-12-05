#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

map<int,int> mp;

// long long nCr[200001][101];
long long fac[200001];
const int mod = 1e9+7;

long long power(long long x, int n) {
	long long res = 1;
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

long long nCr(int n, int r) {
	if (n < r)return 0;
	long long res;
	res = fac[n];
	res *= power(fac[r],mod-2);
	res %= mod;
	res *= power(fac[n-r],mod-2);
	res %= mod;
	return res; 
}

int main() {
	fac[0] = 1;
	for (int i = 1; i <= 2e5; ++i) {
		fac[i] = fac[i-1]*i;
		fac[i] %= mod;
	}
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		int k;// = 2;
		int m;// = 3;
		scanf("%d%d%d",&n,&m,&k);
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			++mp[a];
		}
		auto it = mp.begin();
		auto it2 = mp.begin();
		int pool = 0;
		long long ans = 0;
		for (;it2 != mp.end();) {
			for (;it2->f-it->f <= k;) {
				pool += it2->s;
				++it2;
				if (it2 == mp.end())break;
			}
			if (it2 == mp.end())break;
			ans += nCr(pool,m);
			ans -= nCr(pool-it->s,m);
			ans += mod;
			ans %= mod;
			// printf("%d %d %d %lld <\n",pool,it->f,it2->f,ans);
			pool -= it->s;
			++it;
		}
		for (;it != mp.end();) {
			ans += nCr(pool,m);
			ans -= nCr(pool-it->s,m);
			ans += mod;
			ans %= mod;
			// printf("%d %d %d %lld <<\n",pool,it->f,it2->f,ans);
			pool -= it->s;
			++it;
		}
		printf("%lld\n",ans);
		mp.clear();
	}
	return 0;
}