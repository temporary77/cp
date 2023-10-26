#include <bits/stdc++.h>
using namespace std;

int graph[1000][1000];

int main() {
	freopen("test_input.txt","r",stdin);
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			graph[i][j] = INT_MAX;
		}
		graph[i][i] = 0;
	}
	int a, b, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&w);
		graph[--a][--b] = w;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (graph[j][i] == INT_MAX || graph[i][k] == INT_MAX)continue;
				graph[j][k] = min(graph[j][k],graph[j][i]+graph[i][k]);
			}
		}
		for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	printf("-----\n");
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}