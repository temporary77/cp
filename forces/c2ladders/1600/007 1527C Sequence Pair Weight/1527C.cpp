#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

map<int,vector<int>> mp;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			int a;
			scanf("%d",&a);
			mp[a].push_back(i);
		}
		long long ans = 0;
		for (auto it : mp) {
			long long sum = 0;
			for (auto it2 : it.s) {
				sum += it2;
			}
			long long cur = it.s.size();
			for (auto it2 : it.s) {
				sum -= it2;
				--cur;
				ans += it2*(long long)(n*cur-sum+cur);
			}
		}
		printf("%lld\n",ans);
		mp.clear();
	}
	return 0;
}