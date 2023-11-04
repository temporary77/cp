#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int disc[100001];
int low[100001];
stack<int> stck;
int scc[100001];

int timer = 1;
int idx = 0;

void dfs(int node) {
	disc[node] = timer;
	low[node] = timer;
	stck.push(node);
	// printf("%d %d\n",node,timer);
	++timer;
	for (auto it : graph[node]) {
		if (disc[it] && !scc[it]) {
			low[node] = min(low[node],disc[it]);
		} else if (!disc[it]) {
			dfs(it);
			low[node] = min(low[node],low[it]);
		}
	}
	// printf("%d %d %d\n",node,disc[node],low[node]);
	if (low[node] == disc[node]) {
		// printf("%d <<\n",node);
		++idx;
		for (;!stck.empty();) {
			int x = stck.top();
			stck.pop();
			scc[x] = idx;
			if (x == node)break;
		}
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
	}
	for (int i = 1; i <= n; ++i) {
		if (!disc[i]) {
			dfs(i);
		}
	}
	printf("%d\n",idx);
	for (int i = 1; i <= n; ++i) {
		printf("%d ",scc[i]);
	}
	return 0;
}