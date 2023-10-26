#include <bits/stdc++.h>
using namespace std;

long long graph[71][71];
bool visited[71][71][71];
long long dist[71][71][71];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	long long t;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)continue;
			graph[i][j] = 1e18;
		}
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%lld",&a,&b,&t);
		graph[a][b] = min(graph[a][b],t);
	}
	int k1, q;
	int c, ai, bi;
	scanf("%d%d",&k1,&q);
	k1 = min(k1,n-1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int l = 0; l <= n; ++l) {
				if (i == j)continue;
				dist[i][j][l] = 1e18;
			}
		}		
	}
	for (int l = 1; l <= k1; ++l) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k) {
					dist[i][j][l] = min(dist[i][j][l],dist[i][k][l-1]+graph[k][j]);
				}
			}
		}		
	}
	for (int i = 0; i < q; ++i) {
		scanf("%d%d",&a,&b);
		if (dist[a][b][k1] == 1e18) {
			printf("-1\n");
		} else {
			printf("%d\n",dist[a][b][k1]);
		}
	}
	return 0;
}