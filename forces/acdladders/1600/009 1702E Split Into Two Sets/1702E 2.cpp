#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
bool visited[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			int a, b;
			scanf("%d%d",&a,&b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (int i = 1; i <= n; ++i) {
			if (graph[i].size() != 2) {
				printf("NO\n");
				goto g;
			}
		}
		fill(visited+1,visited+n+1,false);
		for (int i = 1; i <= n; ++i) {
			if (visited[i])continue;
			// if (graph[i][0] == graph[i][1]) {
			// 	visited[graph[i][0]] = true;
			// 	continue;
			// }
			int go = i;
			int cnt = 0;
			for (;;) {
				visited[go] = true;
				// printf("%d ",go);
				++cnt;
				if (visited[graph[go][0]] && visited[graph[go][1]]) {
					break;
				} else if (!visited[graph[go][0]]) {
					go = graph[go][0];
				} else {
					go = graph[go][1];
				}
			}
			// printf("\n%d\n",cnt);
			if (cnt&1) {
				printf("NO\n");
				goto g;
			}
		}
		printf("YES\n");
		g:;
		for (int i = 1; i <= n; ++i) {
			graph[i].clear();
		}
	}
	return 0;
}