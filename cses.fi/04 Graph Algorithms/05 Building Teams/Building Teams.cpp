#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int color[100001];
queue<int> que;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		if (color[i] != 0)continue;
		int c = 1;
		que.push(i);
		color[i] = 1;
		for (;!que.empty();) {
			int t = que.size();
			c = (c&1)+1;
			for (int j = 0; j < t; ++j) {
				int x = que.front();
				que.pop();
				for (auto it : graph[x]) {
					if (color[it] != 0) {
						if (color[it] != c) {
							goto g;
						}
					} else {
						color[it] = c;
						que.push(it);
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ",color[i]);
	}
	return 0;
	g:;
	printf("IMPOSSIBLE");
	return 0;
}