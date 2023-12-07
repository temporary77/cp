#include <bits/stdc++.h>
using namespace std;

bool cat[100001];
int sz[100001];
vector<int> graph[100001];

int n, m;
int ans = 0;

void dfs(int node, int pa, int cur) {
	if (cat[node])++cur;
	else cur = 0;
	if (cur > m)return;
	if (graph[node].size() == 1 && graph[node][0] == pa)++ans;
	for (auto it : graph[node]) {
		if (it == pa)continue;	
		dfs(it,node,cur);
	}
	return;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&cat[i]);
	}
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d",&x,&y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1,-1,0);
	printf("%d\n",ans);
	return 0;
}