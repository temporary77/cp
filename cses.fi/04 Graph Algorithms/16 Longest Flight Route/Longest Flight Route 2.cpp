#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int dist[100001];
int child[100001];

void dfs(int node) {
	for (auto it : graph[node]) {
		if (dist[it] == INT_MIN)dfs(it);
		if (dist[it]+1 > dist[node]) {
			dist[node] = dist[it]+1;
			child[node] = it;
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
	fill(dist,dist+n+1,INT_MIN);
	dist[n] = 1;
	dfs(1);
	if (dist[1] <= 1) {
		printf("IMPOSSIBLE");
		return 0;
	}
	printf("%d\n",dist[1]);
	int x = 1;
	for (;;) {
		printf("%d ",x);
		if (x == n)break;
		x = child[x];
	}
	return 0;
}