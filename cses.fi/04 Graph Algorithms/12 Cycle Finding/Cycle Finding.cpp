#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[2501];
long long dist[2501];
int parent[2501];
queue<pair<long long,int>> que;
stack<int> stck;
bool check[2501];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&c);
		graph[a].push_back({b,c});
	}
	fill(dist,dist+n+1,LLONG_MAX);
	for (int i = 1; i <= n; ++i) {
		if (dist[i] == LLONG_MAX) {
			int l = 1;
			dist[i] = 0;
			que.push({0,i});
			for (int j = 0; j < n; ++j) {
				int t = que.size();
				for (int k = 0; k < t; ++k) {
					long long d;
					int bi;
					tie(d,bi) = que.front();
					que.pop();
					if (dist[bi] < d)continue;
					// printf("%lld %d\n",d,bi);
					for (auto it : graph[bi]) {
						if (dist[it.first] > dist[bi]+it.second) {
							dist[it.first] = dist[bi]+it.second;
							parent[it.first] = bi;
							// printf("%d -> %d\n",bi,it.first);
							que.push({dist[it.first],it.first});
						}
					}
				}
			}
			if (!que.empty()) {
				printf("YES\n");
				int x = parent[que.front().second];
				for (;;) {
					stck.push(x);
					if (check[x]) {
						break;
					}
					check[x] = 1;
					x = parent[x];
				}
				printf("%d ",stck.top());
				stck.pop();
				for (;;) {
					printf("%d ",stck.top());
					if (stck.top() == x)break;
					stck.pop();
				}
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}