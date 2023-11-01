#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int order[100001];
int iter[100001];
int mode;
int knot;

int t = 0;

void dfs(int node, int l) {
	order[node] = l;
	iter[node] = t;
	// printf("%d %d\n",node,t);
	++l;
	// printf("%d\n",node);
	for (auto it : graph[node]) {
		if (iter[it] > 0 && iter[it] < t)continue;
		if (order[it] != 0 && iter[it] == t) {
			knot = it;
			printf("%d\n%d %d ",l-order[it]+1,knot,node);
			mode = 1;
			return;
		}
		dfs(it,l);
		if (mode == 1) {
			printf("%d ",node);
			if (node == knot)mode = 2;
			return;
		}
		if (mode == 2) {
			return;
		}
	}
	order[node] = 0;
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		if (!iter[i]) {
			++t;
			dfs(i,1);
		}
		if (mode == 2)return 0;
	}
	printf("IMPOSSIBLE");
	return 0;
}