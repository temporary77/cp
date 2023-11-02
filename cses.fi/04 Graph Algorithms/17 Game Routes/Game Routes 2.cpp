#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
long long ans[100001];
bool processed[100001];
const int mod = 1e9+7;

void dfs(int node) {
	processed[node] = 1;
	for (auto it : graph[node]) {
		if(!processed[it])dfs(it);
		ans[node] += ans[it];
		ans[node] %= mod;
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
	ans[n] = 1;
	dfs(1);
	printf("%lld",ans[1]);
	return 0;
}