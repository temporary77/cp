#include <bits/stdc++.h>
using namespace std;

vector<int> graph[101][101];
int cc[101][101];
int idx;
int color;

void dfs(int node) {
	cc[color][node] = idx;
	for (auto it : graph[color][node]) {
		if (cc[color][it])continue;
		dfs(it);
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		graph[c][a].push_back(b);
		graph[c][b].push_back(a);
	}
	for (int i = 1; i <= m; ++i) {
		idx = 0;
		color = i;
		for (int j = 1; j <= n; ++j) {
			if (!cc[i][j]) {
				++idx;
				dfs(j);
			}
		}
	}
	int q;
	scanf("%d",&q);
	for (int qi = 0; qi < q; ++qi) {
		int u, v;
		scanf("%d%d",&u,&v);
		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			if (cc[i][u] == cc[i][v])++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}