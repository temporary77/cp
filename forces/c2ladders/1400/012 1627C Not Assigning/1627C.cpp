#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int ans[100001];
vector<int> edges[100001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			graph[i].clear();
		}
		for (int i = 0; i < n-1; ++i) {
			edges[i].clear();
		}
		bool check = true;
		for (int i = 0; i < n-1; ++i) {
			int u, v;
			scanf("%d%d",&u,&v);
			for (auto it : graph[u]) {
				edges[i].push_back(it);
				edges[it].push_back(i);
			}
			for (auto it : graph[v]) {
				edges[i].push_back(it);
				edges[it].push_back(i);
			}
			graph[u].push_back(i);
			graph[v].push_back(i);
			if (graph[u].size() > 2 || graph[v].size() > 2) {
				check = false;
			}
		}
		if (!check) {
			printf("-1\n");
			goto g;
		}
		fill(ans,ans+n,0);
		for (int i = 0; i < n-1; ++i) {
			if (!ans[i]) {
				ans[i] = 2;
				for (auto it : edges[i]) {
					ans[it] = 3;
				}
			} else {
				for (auto it : edges[i]) {
					ans[it] = ((ans[i]-1)&1)+2;
				}
			}
			printf("%d ",ans[i]);
		}
		printf("\n");
		g:;
	}
	return 0;
}