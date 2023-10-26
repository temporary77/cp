#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
bool visited[200001];
bool marked[200001];
int ans;

void dfs(int node) {
	visited[node] = 1;
	for (auto it : graph[node]) {
		if (visited[it])continue;
		dfs(it);
		if (!marked[node] && !marked[it]) {
			marked[node] = 1;
			marked[it] = 1;
			++ans;
		}
	}
	return;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}