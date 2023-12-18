#include <bits/stdc++.h>
using namespace std;

map<int,long long> mp;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		long long ans = 0;
		long long cur = 0;
		for (int i = 1; i <= n; ++i) {
			int a;
			scanf("%d",&a);
			cur += mp[a];
			ans += cur;
			mp[a] += i;
		}
		printf("%lld\n",ans);
		mp.clear();
	}
	return 0;
}