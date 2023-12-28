#include <bits/stdc++.h>
using namespace std;

vector<int> graph[400001];
int degree[400001];
queue<int> que;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		for (int i = 0; i < n-1; ++i) {
			int u, v;
			scanf("%d%d",&u,&v);
			graph[u].push_back(v);
			graph[v].push_back(u);
			++degree[u];
			++degree[v];
		}
		for (int i = 1; i <= n; ++i) {
			if (degree[i] <= 1) {
				que.push(i);
			}
		}
		int removed = que.size();
		// printf("%d %d %d\n",n,k,que.size());
		for (int i = 2; i <= k && que.size(); ++i) {
			int s = que.size();
			// printf("%d\n",s);
			for (int j = 0; j < s; ++j) {
				int x = que.front();
				que.pop();
				// printf("%d %d\n",i,x);
				for (auto it : graph[x]) {
					if (degree[it] >= 2) {
						--degree[it];
						if (degree[it] == 1)que.push(it);
					}
				}
			}
			removed += que.size();
		}
		printf("%d\n",n-removed);
		for (int i = 1; i <= n; ++i) {
			graph[i].clear();
			degree[i] = 0;
		}
		for(;que.size();)que.pop();
	}
	return 0;
}