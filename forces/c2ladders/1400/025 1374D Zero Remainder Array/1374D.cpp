#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		int max1 = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			int need = k-((a-1)%k)-1;
			if (need)++mp[k-((a-1)%k)-1];
		}
		long long ans = 0;
		for (auto it : mp) {
			ans = max(ans,it.first+(it.second-1)*(long long)k+1);
		}
		printf("%lld\n",ans);
		mp.clear();
	}
	return 0;
}