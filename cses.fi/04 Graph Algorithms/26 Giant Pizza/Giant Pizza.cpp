#include <bits/stdc++.h>
using namespace std;

vector<int> graph1[200001];
vector<int> graph2[200001];
bool visited[200001];
int scc[200001];
int ans[100001];
stack<int> stck;

void dfs(int node) {
	visited[node] = 1;
	for (auto it : graph1[node]) {
		if (!visited[it]) {
			dfs(it);
		}
	}
	stck.push(node);
	return;
}

int idx = 0;

void kosaraju(int node) {
	scc[node] = idx;
	// printf("%d %d\n",idx,node);
	for (auto it : graph2[node]) {
		if (!scc[it]) {
			kosaraju(it);
		}
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	char ca, cb;
	int a, b;
	for (int i = 0; i < n; ++i) {
		scanf(" %c%d %c%d",&ca,&a,&cb,&b);
		if (ca == '-') {
			a += 100000;
		}
		if (cb == '-') {
			b += 100000;
		}
		int ai = (a+100000-1)%200000+1;
		int bi = (b+100000-1)%200000+1;
		graph1[bi].push_back(a);
		graph1[ai].push_back(b);
		graph2[a].push_back(bi);
		graph2[b].push_back(ai);
	}
	for (int i = 1; i <= m; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	for (int i = 100001; i <= m+100000; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	for (;!stck.empty();) {
		int x = stck.top();
		stck.pop();
		// printf("%d <\n",x);
		if (!scc[x]) {
			++idx;
			kosaraju(x);
		}
	}
	for (int i = 1; i <= m; ++i) {
		int invrs = i+100000;
		if (scc[i] == scc[invrs]) {
			printf("IMPOSSIBLE");
			return 0;
		} else if (scc[i] < scc[invrs]) {
			ans[i] = -1;
		} else {
			ans[i] = 1;
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (ans[i] == 1) {
			printf("+ ");
		} else {
			printf("- ");
		}
	}
	return 0;
}