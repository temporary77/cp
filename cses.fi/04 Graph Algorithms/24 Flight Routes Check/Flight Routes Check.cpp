#include <bits/stdc++.h>
using namespace std;

vector<int> graph1[100001];
vector<int> graph2[100001];
bool visited1[100001];
bool visited2[100001];

void dfs1(int node) {
	visited1[node] = 1;
	for (auto it : graph1[node]) {
		if (!visited1[it]) {
			dfs1(it);
		}
	}
	return;
}

void dfs2(int node) {
	visited2[node] = 1;
	for (auto it : graph2[node]) {
		if (!visited2[it]) {
			dfs2(it);
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
		graph1[a].push_back(b);
		graph2[b].push_back(a);
	}
	dfs1(1);
	for (int i = 1; i <= n; ++i) {
		if (!visited1[i]) {
			printf("NO\n%d %d",1,i);
			return 0;		
		}
	}
	dfs2(1);
	for (int i = 1; i <= n; ++i) {
		if (!visited2[i]) {
			printf("NO\n%d %d",i,1);
			return 0;		
		}
	}
	printf("YES");
	return 0;
}