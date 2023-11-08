#include <bits/stdc++.h>
using namespace std;

vector<int> graph1[101];
vector<int> graph2[101];
bool visited1[101];
bool visited2[101];

void dfs(int node) {
	visited1[node] = 1;
	for (auto it : graph1[node]) {
		if (visited2[it])continue;
		visited2[it] = 1;
		for (auto it2 : graph2[it]) {
			if (visited1[it2])continue;
			dfs(it2);
		}
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int k, a;
	bool check = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		if (k)check = 1;
		for (int j = 0; j < k; ++j) {
			scanf("%d",&a);
			graph1[i].push_back(a);
			graph2[a].push_back(i);
		}
	}
	if (!check) {
		printf("%d",n);
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (!visited1[i]) {
			dfs(i);
			++cnt;
		}
	}
	printf("%d",cnt-1);
	return 0;
}