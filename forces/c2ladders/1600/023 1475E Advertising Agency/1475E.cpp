#include <bits/stdc++.h>
using namespace std;

int cnt[1001];
vector<int> vctr;
const int mod = 1e9+7;
long long inversenum[1001];
long long fac[1001];
long long inversefac[1001];

long long nCr(int n, int r) {
	long long res = fac[n];
	res *= inversefac[r];
	res %= mod;
	res *= inversefac[n-r];
	res %= mod;
	return res;
}

int main() {
	inversenum[1] = 1;
	fac[0] = 1;
	fac[1] = 1;
	inversefac[0] = 1;
	inversefac[1] = 1;
	for (int i = 2; i <= 1000; ++i) {
		inversenum[i] = (mod-mod/i)*(inversenum[mod%i]);
		inversenum[i] %= mod;
		fac[i] = fac[i-1]*i;
		fac[i] %= mod;
		inversefac[i] = inversefac[i-1]*inversenum[i];
		inversefac[i] %= mod;
	}
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		fill(cnt+1,cnt+n+1,0);
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			vctr.push_back(a);
			++cnt[a];
		}
		sort(vctr.begin(),vctr.end(),greater<int>());
		int choosing = vctr[k-1];
		int exclude = 0;
		for (int i = n; i > choosing; --i) {
			exclude += cnt[i];
		}
		printf("%lld\n",nCr(cnt[choosing],k-exclude));
		vctr.clear();
	}
	return 0;
}