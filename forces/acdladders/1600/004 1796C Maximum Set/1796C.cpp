#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long invnum[21];
long long invfac[21];
long long fac[21];

#define f first
#define s second

map<int,int> mp;

int main() {
	fac[0] = 1;
	fac[1] = 1;
	invnum[1] = 1;
	invfac[0] = 1;
	invfac[1] = 1;
	for (int i = 2; i <= 20; ++i) {
		fac[i] = fac[i-1]*i;
		fac[i] %= mod;
	}
	for (int i = 2; i <= 20; ++i) {
		invnum[i] = (mod-mod/i)*invnum[mod%i];
		invnum[i] %= mod;
	}
	for (int i = 2; i <= 20; ++i) {
		invfac[i] = invfac[i-1]*invnum[i];
		invfac[i] %= mod;
	}
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int l, r;
		scanf("%d%d",&l,&r);
		int x = l;
		int max1 = 1;
		if (l != 1)++mp[l];
		long long cur = l;
		for (;x*2 <= r;) {
			++mp[2];
			cur *= 2;
			++max1;
			x *= 2;
		}
		long long ans = 0;
		int ttt = 0;
		for (;;) {
			// int ii = 0;
			for (;cur <= r;) {
				// if (++ii > 100)break;
				// printf("%lld\n",cur);
				// for (auto it : mp) {
				// 	printf("<%d,%d> ",it);
				// }
				// printf("\n");
				if (cur >= l) {
					long long res = fac[l == 1 ? max1-1 : max1];
					int validstarts = 0;
					for (auto it : mp) {
						// for (int i = 0; i < it.s; ++i)printf("%d ",it.f);
						res *= invfac[it.s];
						res %= mod;
						if (it.f >= l)validstarts += it.s;
					}
					res *= validstarts;
					res %= mod;
					res *= invnum[l == 1 ? max1-1 : max1];
					res %= mod;
					ans += res;
					ans %= mod;
					// printf("\n");
				}
				int key = mp.rbegin()->f;
				cur *= (key+1);
				cur /= key;
				--mp[key];
				if (mp[key] == 0)mp.erase(key);
				++mp[key+1];
			}
			// ++ttt;
			// if (ttt >= 100)break;
			// for (auto it : mp) {
			// 	printf("[%d,%d] ",it);
			// }
			// printf("\n");
			// printf("[%d]",mp.size());
			if (mp.size() <= 1)break;
			int k = mp.rbegin()->f;
			int s = (++mp.rbegin())->f;
			cur *= s+1;
			cur /= s;
			--mp[s];
			if (mp[s] == 0)mp.erase(s);
			++mp[s+1];
			for (int i = 0; i < mp[k]; ++i) {
				cur *= s+1;
				cur /= k;
				// printf("%d --- %lld\n",k,cur/k);
				// if (i > 10)break;
			}
			mp[s+1] += mp[k];
			// printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! %lld %d %d\n",cur,k,s);
			// for (auto it : mp) {
			// 	printf("(%d,%d) ",it);
			// }
			// printf("\n");
			mp.erase(k);
		}
		printf("%d %lld\n",max1,ans);
		mp.clear();
	}
	return 0;
}