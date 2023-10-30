#include <bits/stdc++.h>
using namespace std;

long long graph[501][501];

int main() {
	int n, m, q;
	scanf("%d%d%d",&n,&m,&q);
	int a, b;
	long long c;
	for (int i = 0; i < n; ++i) {
		fill(graph[i],graph[i]+n,1e18);
		graph[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%lld",&a,&b,&c);
		--a; --b;
		graph[a][b] = min(graph[a][b],c);
		graph[b][a] = min(graph[b][a],c);
	}
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		printf("%lld ",graph[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == k || k == j || i == j)continue;
				graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
			}
		}
	}
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		printf("%lld ",graph[i][j]);
	// 	}
	// 	printf("\n");
	// }
	long long ans;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d",&a,&b);
		--a; --b;
		ans = graph[a][b];
		if (ans == 1e18)printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}