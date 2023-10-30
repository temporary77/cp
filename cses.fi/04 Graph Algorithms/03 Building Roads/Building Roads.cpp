#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
vector<int> vctr;

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
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; ++i) {
		if (!visited[i]) {
			dfs(i);
			vctr.push_back(i);
		}
	}
	printf("%d\n",vctr.size());
	for (auto it : vctr) {
		printf("1 %d\n",it);
	}
	return 0;
}