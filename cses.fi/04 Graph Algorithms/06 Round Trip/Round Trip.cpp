#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int parent[100001];
vector<int> vctr;
int mode = 0;
int knot = -1;

void dfs(int node) {
	// printf("%d\n",node);
	for (auto it : graph[node]) {
		if (parent[node] == it)continue;
		// printf("%d -> %d\n",node,it);
		if (parent[it] != 0) {
			knot = it;
			// printf("---- %d ----\n",knot);
			vctr.push_back(it);
			vctr.push_back(node);
			// printf("%d <<\n",it);
			// printf("%d <<\n",node);
			mode = 1;
			return;
		} else {
			parent[it] = node;
			dfs(it);
			// printf("%d %d %d\n",node,it,mode);
			if (mode == 1) {
				vctr.push_back(node);
				// printf("%d <<<\n",node);
				if (node == knot)mode = 2;
				return;
			} else if (mode == 2) {
				return;
			}
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
	for (int i = 1; i <= n; ++i) {
		if (mode == 2)goto g;
		if (parent[i] == 0) {
			parent[i] = -1;
			dfs(i);
		}
	}
	printf("IMPOSSIBLE");
	return 0;
	g:;
	printf("%d\n",vctr.size());
	for (auto it : vctr) {
		printf("%d ",it);
	}
	return 0;
}