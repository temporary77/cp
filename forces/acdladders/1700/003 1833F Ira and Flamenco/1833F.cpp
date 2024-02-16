#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int,int>> vctr2;

map<int,int> mp;

const int mod = 1e9+7;

long long modinverse(long long x) {
	long long res = 1;
	int n = mod-2;
	for (;n;) {
		if (n&1) {
			res *= x;
			res %= mod;
		}
		x *= x;
		x %= mod;
		n /= 2;
	}
	return res;
}

signed main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		scanf("%d%d",&n,&m);
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			++mp[a];
		}
		for (auto it : mp) {
			vctr2.push_back({it.f,it.s});
		}
		int l = 0, r = m-1;
		long long ans = 0;
		long long cur = 1;
		if (m > vctr2.size()) {
			goto g;
		}
		for (int i = l; i < r; ++i) {
			cur *= vctr2[i].s;
			cur %= mod;
		}
		for (;r < vctr2.size();) {
			cur *= vctr2[r].s;
			cur %= mod;
			if (vctr2[r].f-vctr2[l].f < m) {
				ans += cur;
				ans %= mod;
			}
			cur *= modinverse(vctr2[l].s);
			cur %= mod;
			++l;
			++r;
		}
		g:;
		printf("%lld\n",ans);
		mp.clear();
		vctr2.clear();
	}
	return 0;
}