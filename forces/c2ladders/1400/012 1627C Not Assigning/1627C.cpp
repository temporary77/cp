#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[100001];
int ans[100001];
bool visited[100001];

void dfs(int node, int c) {
	visited[node] = true;
	for (auto it : graph[node]) {
		// printf("%d %d %d\n",node,it.first,it.second);
		if (!visited[it.second]) {
			ans[it.first] = c;
			// printf("> %d %d\n",it.first,c);
			dfs(it.second,((c-1)&1)+2);
		}
	}
	return;
}

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			graph[i].clear();
		}
		bool check = true;
		for (int i = 0; i < n-1; ++i) {
			int u, v;
			scanf("%d%d",&u,&v);
			graph[u].push_back({i,v});
			graph[v].push_back({i,u});
			if (graph[u].size() > 2 || graph[v].size() > 2) {
				check = false;
			}
		}
		if (!check) {
			printf("-1\n");
			goto g;
		}
		fill(ans,ans+n-1,0);
		fill(visited+1,visited+n+1,false);
		for (int i = 1; i <= n; ++i) {
			if (graph[i].size() == 1 && !visited[i]) {
				// printf("%d ?\n",i);
				dfs(i,2);
			}
		}
		for (int i = 0; i < n-1; ++i) {
			printf("%d ",ans[i]);
		}
		printf("\n");
		g:;
	}
	return 0;
}