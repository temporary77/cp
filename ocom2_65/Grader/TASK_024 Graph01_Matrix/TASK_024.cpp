#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	bool graph[n][n] = {0};
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[--a][--b] = 1;
		graph[b][a] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}

	return 0;
}