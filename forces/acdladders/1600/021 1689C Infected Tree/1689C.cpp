#include <bits/stdc++.h>
using namespace std;

vector<int> graph[300001];

int dfs(int node, int pa) {
	if (graph[node].size() <= 2) {
		return graph[node].size();
	}
	int min1 = INT_MAX;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		min1 = min(min1,dfs(it,node));
	}
	return min1+2;
}

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d",&u,&v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		graph[1].push_back(-1);
		printf("%d\n",n-dfs(1,-1));
		for (int i = 1; i <= n; ++i) {
			graph[i].clear();
		}
	}
	return 0;
}