#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<pair<int,vector<int>>,int>> vctr;
vector<tuple<int,int,int>> ans;

bool comp(pair<pair<int,vector<int>>,int> a, pair<pair<int,vector<int>>,int> b) {
	return a.f.f > b.f.f;
}

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		scanf("%d%d",&n,&m);
		int ttl = 0;
		for (int i = 0; i < n; ++i) {
			pair<pair<int,vector<int>>,int> temp = {{0,vector<int>()},i+1};
			vctr.push_back(temp);
			for (int j = 0; j < m; ++j) {
				int x;
				scanf("%d",&x);
				if (x) {
					vctr[i].f.s.push_back(1);
					++vctr[i].f.f;
				}
				else vctr[i].f.s.push_back(0);
			}
			ttl += vctr[i].f.f;
		}
		if (ttl%n) {
			printf("-1\n");
			vctr.clear();
			continue;
		}
		sort(vctr.begin(),vctr.end(),comp);
		int l = 0, r = n-1;
		int k = ttl/n;
		int cur1 = vctr[l].f.f;
		int cur2 = vctr[r].f.f;
		int idx = 0;
		for (;;) {
			// printf("%d %d %d\n",vctr[l].s,vctr[r].s,idx);
			for (;cur1 == k && l < n;) {
				++l;
				idx = 0;
				cur1 = vctr[l].f.f;
			}
			for (;cur2 == k && r >= 0;) {
				--r;
				idx = 0;
				cur2 = vctr[r].f.f;
			}
			if (l >= r)break;
			for (;!(vctr[l].f.s[idx] == 1 && vctr[r].f.s[idx] == 0);) {
				++idx;
				if (idx >= m) {
					printf("no");
					return 0;
				}
			}
			--cur1;
			++cur2;
			vctr[l].f.s[idx] = 0;
			vctr[r].f.s[idx] = 1;
			ans.push_back({vctr[l].s,vctr[r].s,idx+1});
		}
		printf("%d\n",ans.size());
		for (auto it : ans) {
			printf("%d %d %d\n",get<0>(it),get<1>(it),get<2>(it));
		}
		vctr.clear();
		ans.clear();
	}
	return 0;
}