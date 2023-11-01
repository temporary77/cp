#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int indegree[100001];
int parent[100001];
int dist[100001];
queue<int> que;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		graph[b].push_back(a);
		++indegree[a];
	}
	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0) {
			parent[i] = -1;
			que.push(i);
		}
	}
	dist[n] = 1;
	for (;!que.empty();) {
		int x = que.front();
		que.pop();
		for (auto it : graph[x]) {
			--indegree[it];
			if (dist[x] != 0) {
				dist[it] = dist[x]+1;
				parent[it] = x;
			}
			if (indegree[it] == 0) {
				// printf("%d->%d\n",x,it);
				que.push(it);
			}
		}
		if (x == 1) {
			if (dist[x] == 0) {
				printf("IMPOSSIBLE");
				return 0;
			}
			printf("%d\n",dist[x]);
			for (;;) {
				printf("%d ",x);
				if (x == n)return 0;
				x = parent[x];
			}
		}
	}
	return 0;
}