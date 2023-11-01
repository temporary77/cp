#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int visited[100001];
stack<int> stck;
bool abort1 = 0;

void dfs(int node) {
	visited[node] = 1;
	for (auto it : graph[node]) {
		if (abort1)return;
		if (visited[it] == 2)continue;
		if (visited[it] == 1) {
			abort1 = 1;
			return;
		}
		// printf("%d ? %d\n",node,it);
		if (!visited[it]) {
			// printf("%d -> %d\n",node,it);
			dfs(it);
		}
	}
	// printf("%d\n",node);
	stck.push(node);
	visited[node] = 2;
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
		if (abort1) {
			printf("IMPOSSIBLE");
			return 0;
		}
	}
	for (;!stck.empty();) {
		printf("%d ",stck.top());
		stck.pop();
	}
	return 0;
}