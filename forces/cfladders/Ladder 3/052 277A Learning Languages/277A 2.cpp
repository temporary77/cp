#include <bits/stdc++.h>
using namespace std;

vector<int> graph[101];
bool active[101];
bool visited[101];

void dfs(int node) {
	visited[node] = 1;
	for (auto it : graph[node]) {
		if (!visited[it]) {
			dfs(it);
		}
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d",&k);
		if (k == 0) {
			++ans;
			continue;
		}
		int x;
		scanf("%d",&x);
		active[x] = 1;
		if (k == 1) {
			continue;
		}
		int a;
		for (int j = 1; j < k; ++j) {
			scanf("%d",&a);
			graph[x].push_back(a);
			graph[a].push_back(x);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= m; ++i) {
		if (active[i] && !visited[i]) {
			++cnt;
			dfs(i);
		}
	}
	ans += max(cnt-1,0);
	printf("%d",ans);
	return 0;
}