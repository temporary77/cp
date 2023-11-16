#include <bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> mp;
int ans[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		int x;
		int ttl = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&x);
			if (mp[x].size() < k) {
				mp[x].push_back(i);
				++ttl;
			}
			ans[i] = 0;
		}
		ttl -= ttl%k;
		int c = 0;
		for (auto it : mp) {
			for (auto it2 : it.second) {
				++c;
				ans[it2] = c;
				c %= k;
				--ttl;
				if (ttl == 0)goto g;
			}
		}
		g:;
		for (int i = 0; i < n; ++i) {
			printf("%d ",ans[i]);
		}
		printf("\n");
		mp.clear();
	}
	return 0;
}