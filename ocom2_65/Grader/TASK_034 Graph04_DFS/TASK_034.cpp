#include <bits/stdc++.h>
using namespace std;

set<int> graph[100005];
bool visited[100005];

void recursion(int k) {
	visited[k] = 1;
	printf("%d ",k+1);
	for (auto it : graph[k]) {
		if (visited[it] == 0) {
			recursion(it);			
		}
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[--a].insert(--b);
		graph[b].insert(a);
	}
	int k;
	scanf("%d",&k);
	recursion(--k);
	return 0;
}