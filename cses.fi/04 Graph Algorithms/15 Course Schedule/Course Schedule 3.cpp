#include <bits/stdc++.h>
using namespace std;
 
vector<int> graph[100001];
bool visited[100001];
stack<int> stck;
int order[100001];

int o = 1;

void dfs(int node) {
	visited[node] = 1;
	for (auto it : graph[node]) {
		// printf("%d ? %d\n",node,it);
		if (!visited[it]) {
			// printf("%d -> %d\n",node,it);
			dfs(it);
		}
	}
	// printf("%d\n",node);
	order[node] = o;
	++o;
	stck.push(node);
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
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (auto it : graph[i]) {
			if (order[i] < order[it]) {
				printf("IMPOSSIBLE");
				return 0;
			}
		}
	}
	for (;!stck.empty();) {
		printf("%d ",stck.top());
		stck.pop();
	}
	return 0;
}