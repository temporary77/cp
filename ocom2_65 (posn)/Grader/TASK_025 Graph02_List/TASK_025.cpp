#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	set<int> graph[n];
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[--a].insert(--b);
		graph[b].insert(a);
	}
	for (int i = 0; i < n; ++i) {
		printf("%d | ",i+1);
		for (auto j : graph[i]) {
			printf("%d ",j+1);
		}
		printf("\n");
	}
	return 0;
}