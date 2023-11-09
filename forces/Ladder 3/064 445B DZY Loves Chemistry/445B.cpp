#include <bits/stdc++.h>
using namespace std;

vector<int> graph[51];
bool visited[51];
int ans = 0;
int cur;

void dfs(int node) {
	visited[node] = 1;
	++cur;
	for (auto it : graph[node]) {
		if (visited[it])continue;
		dfs(it);
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			cur = 0;
			dfs(i);
			ans += cur-1;
		}
	}
	printf("%lld",1LL << (ans));
	return 0;
}