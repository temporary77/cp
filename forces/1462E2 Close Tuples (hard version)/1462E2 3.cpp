#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

map<int,int> mp;

long long fac[200001];
long long inversenum[200001];
long long inversefac[200001];
const int mod = 1e9+7;

long long nCr(int n, int r) {
	if (n < r)return 0;
	long long res = fac[n];
	res *= inversefac[r];
	res %= mod;
	res *= inversefac[n-r];
	res %= mod;
	return res;
}

int main() {
	fac[0] = 1;
	for (int i = 1; i <= 2e5; ++i) {
		fac[i] = fac[i-1]*i;
		fac[i] %= mod;
	}
	inversenum[0] = 0;
	inversenum[1] = 1;
	for (int i = 2; i <= 2e5; ++i) {
		inversenum[i] = (mod-mod/i)*inversenum[mod%i];
		inversenum[i] %= mod;
	}
	inversefac[0] = 1;
	for (int i = 1; i <= 2e5; ++i) {
		inversefac[i] = inversefac[i-1]*inversenum[i];
		inversefac[i] %= mod;
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