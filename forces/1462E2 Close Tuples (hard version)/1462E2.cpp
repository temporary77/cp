#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

map<int,int> mp;

long long nCr[200001][101];
const int mod = 1e9+7;

int main() {
	for (int i = 0; i <= 2e5; ++i) {
		nCr[i][0] = 1;
	}
	for (int j = 0; j <= 100; ++j) {
		nCr[j][j] = 1;
	}
	for (int j = 1; j <= 100; ++j) {
		for (int i = j+1; i <= 2e5; ++i) {
			nCr[i][j] = nCr[i-1][j]+nCr[i-1][j-1];
			nCr[i][j] %= mod;
		}
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
			ans += nCr[pool][m];
			ans -= nCr[pool-it->s][m];
			ans += mod;
			ans %= mod;
			// printf("%d %d %d %lld <\n",pool,it->f,it2->f,ans);
			pool -= it->s;
			++it;
		}
		for (;it != mp.end();) {
			ans += nCr[pool][m];
			ans -= nCr[pool-it->s][m];
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