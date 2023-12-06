#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

long long qs[200001];
map<long long,int> mp;

vector<pair<int,int>> vctr;

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d",&a);
		qs[i] = qs[i-1]+a;
	}
	int l = 0;
	int r = 0;
	mp[qs[0]] = 0;
	for (;;) {
		++r;
		if (r > n)break;
		if (mp.find(qs[r]) != mp.end()) {
			for (;l < mp[qs[r]];) {
				mp.erase(qs[l]);
				++l;
			}
			++l;
			vctr.emplace_back(l,r);
			// printf("%d %d\n",l,r);
		}
		mp[qs[r]] = r;
	}
	int ans = 0;
	for (int i = 0; i < vctr.size();) {
		++ans;
		int idx = vctr[i].s;
		for (;vctr[i].f < idx && i < vctr.size();)++i;
	}
	printf("%d\n",ans);
	return 0;
}