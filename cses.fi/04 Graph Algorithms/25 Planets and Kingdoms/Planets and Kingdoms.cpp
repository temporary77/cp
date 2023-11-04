#include <bits/stdc++.h>
using namespace std;

vector<int> graph1[100001];
vector<int> graph2[100001];
stack<int> stck;
bool visited1[100001];
int scc[100001];

void dfs(int node) {
	visited1[node] = 1;
	for (auto it : graph1[node]) {
		if (!visited1[it])dfs(it);
	}
	stck.push(node);
	return;
}

int idx = 0;

void kosaraju(int node) {
	scc[node] = idx;
	for (auto it : graph2[node]) {
		if (!scc[it])kosaraju(it);
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
		if (!visited1[i]) {
			dfs(i);
		}
	}
	for (;!stck.empty();) {
		int x = stck.top();
		stck.pop();
		if (!scc[x]) {
			++idx;
			kosaraju(x);
		}
	}
	printf("%d\n",idx);
	for (int i = 1; i <= n; ++i) {
		printf("%d ",scc[i]);
	}
	return 0;
}