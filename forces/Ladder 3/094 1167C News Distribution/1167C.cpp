#include <bits/stdc++.h>
using namespace std;

vector<int> graph1[500001];
vector<int> graph2[500001];
bool visited[500001];
int cc[500001];
vector<int> vctr = {-1};

int cur;
int idx = 0;

void dfs(int node) {
	cc[node] = idx;
	++cur;
	for (auto it : graph1[node]) {
		if (visited[it])continue;
		visited[it] = true;
		for (auto it2 : graph2[it]) {
			if (!cc[it2]) {
				dfs(it2);
			}
		}
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; ++i) {
		int k;
		scanf("%d",&k);
		int x;
		for (int j = 0; j < k; ++j) {
			scanf("%d",&x);
			--x;
			graph1[x].push_back(i);
			graph2[i].push_back(x);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!cc[i]) {
			cur = 0;
			++idx;
			dfs(i);
			vctr.push_back(cur);
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ",vctr[cc[i]]);
	}
	return 0;
}