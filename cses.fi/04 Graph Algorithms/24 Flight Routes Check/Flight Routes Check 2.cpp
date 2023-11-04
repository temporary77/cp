#include <bits/stdc++.h>
using namespace std;

vector<int> graph1[100001];
vector<int> graph2[100001];
bool visited[100001];

int top1;

void topsort(int node) {
	visited[node] = 1;
	for (auto it : graph1[node]) {
		if (!visited[it])topsort(it);
	}
	top1 = node;
	return;
}

void dfs(int node) {
	visited[node] = 0;
	for (auto it : graph2[node]) {
		if (visited[it])dfs(it);
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		graph1[a].push_back(b);
		graph2[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			topsort(i);
		}
	}
	dfs(top1);
	for (int i = 1; i <= n; ++i) {
		if (top1 == i)continue;
		if (visited[i]) {
			printf("NO\n%d %d",i,top1);
			return 0;
		}
	}
	printf("YES");
	return 0;
}