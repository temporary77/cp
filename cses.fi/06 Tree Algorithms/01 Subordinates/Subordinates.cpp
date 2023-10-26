#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
int ans[200001];

int dfs(int node) {
	int res = 0;
	for (auto it : graph[node]) {
		res += dfs(it);
	}
	ans[node] = res;
	return res+1;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 2; i <= n; ++i) {
		int k;
		scanf("%d",&k);
		graph[k].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		printf("%d ",ans[i]);
	}
	return 0;
}