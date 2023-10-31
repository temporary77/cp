#include <bits/stdc++.h>
using namespace std;

vector<int> graph1[100001];
vector<int> graph2[100001];
vector<tuple<int,int,int>> edges;
bool visited1[100001];
bool visited2[100001];
long long dist[100001];

void dfs1(int node) {
	visited1[node] = 1;
	for (auto it : graph1[node]) {
		if (visited1[it])continue;
		dfs1(it);
	}
	return;
}

void dfs2(int node) {
	visited2[node] = 1;
	for (auto it : graph2[node]) {
		if (visited2[it])continue;
		dfs2(it);
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b, x;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&x);
		--a; --b;
		graph1[a].push_back(b);
		graph2[b].push_back(a);
		edges.push_back({a,b,x});
	}
	dfs1(0);
	dfs2(n-1);
	fill(dist,dist+n,LLONG_MIN);
	dist[0] = 0;
	for (int i = 0; i < n; ++i) {
		bool check = 0;
		for (int j = 0; j < m; ++j) {
			int ai, bi, xi;
			tie(ai,bi,xi) = edges[j];
			if (dist[ai] == LLONG_MIN)continue;
			if (dist[bi] < dist[ai]+xi) {
				if (i == n-1) {
					if (visited1[bi] && visited2[bi]) {
						printf("-1");
						return 0;
					}
				}
				check = 1;
				dist[bi] = dist[ai]+xi;
			}
		}
		if (!check)break;
	}
	printf("%lld",dist[n-1]);
	return 0;
}