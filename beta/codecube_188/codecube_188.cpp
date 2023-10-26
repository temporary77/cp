#include <bits/stdc++.h>
using namespace std;

int n, q;
unordered_map<int,vector<int>> mp;

int main() {
	scanf("%d%d",&n,&q);
	int k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&k);
		mp[k].push_back(i);
	}
	for (auto it : mp) {
		sort(it.second.begin(),it.second.end());
	}
	int a, b;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d",&a,&b,&k);
		if (mp.find(k) == mp.end()) {
			printf("0\n");
			continue;
		} else {
			auto it = upper_bound(mp[k].begin(),mp[k].end(),b);
			auto it2 = lower_bound(mp[k].begin(),mp[k].end(),a);
			//printf("%d %d\n",*it,*it2);
			if (it == mp[k].begin() || it2 == mp[k].end()) {
				printf("0\n");
				continue;				
			}
			printf("%d\n",(--it)-it2+1);
		}
	}
	return 0;
}