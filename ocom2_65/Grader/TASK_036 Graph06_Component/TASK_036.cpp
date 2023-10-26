#include <bits/stdc++.h>
using namespace std;

set<int> graph[100005];
bool visited[100005];

void recursion(int k) {
	visited[k] = 1;
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
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (visited[i] == 0) {
			recursion(i);
			++cnt;
		}
	}
	printf("%d",cnt);
	return 0;
}