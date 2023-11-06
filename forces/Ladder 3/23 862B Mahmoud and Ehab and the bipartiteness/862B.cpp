#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
long long color[2];

void dfs(int node, int pa, int c) {
	++color[c];
	for (auto it : graph[node]) {
		if (it == pa)continue;
		dfs(it,node,c^1);
	}
	return;
}

int main() {
	int n;
	scanf("%d",&n);
	int u, v;
	for (int i = 0; i < n-1; ++i) {
		scanf("%d%d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1,-1,0);
	printf("%lld",color[0]*color[1]-n+1);
	return 0;
}