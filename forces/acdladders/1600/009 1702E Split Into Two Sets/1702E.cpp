#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
vector<int> edges[200001];
int visited[200001];
queue<int> que;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			int a, b;
			scanf("%d%d",&a,&b);
			edges[a].push_back(i);
			edges[b].push_back(i);
		}
		int c = 1;
		for (int i = 1; i <= n; ++i) {
			if (edges[i].size() != 2) {
				printf("NO\n");
				goto g;
			}
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}
		fill(visited+1,visited+n+1,0);
		for (int i = 1; i <= n; ++i) {
			if (visited[i])continue;
			visited[i] = c;
			que.push(i);
			for (;que.size();) {
				int s = que.size();
				c = (c%2)+1;
				for (int i = 0; i < s; ++i) {
					int x = que.front();
					que.pop();
					visited[x] = c;
					// printf("%d %d\n",x,c);
					for (auto it : graph[x]) {
						if (!visited[it]) {
							que.push(it);
						} else if (visited[it] == c) {
							printf("NO\n");
							goto g;
						}
					}
				}
			}
		}
		printf("YES\n");
		g:;
		for (;que.size();)que.pop();
		for (int i = 1; i <= n; ++i) {
			graph[i].clear();
			edges[i].clear();
		}
	}
	return 0;
}