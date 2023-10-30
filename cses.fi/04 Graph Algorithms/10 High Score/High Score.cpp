#include <bits/stdc++.h>
using namespace std;

vector<pair<int,long long>> graph[2501];
long long dist[2501];
queue<pair<long long,int>> que;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	long long x;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%lld",&a,&b,&x);
		--a; --b;
		graph[a].push_back({b,x});
	}
	fill(dist,dist+n,LLONG_MIN);
	dist[0] = 0;
	que.push({0,0});
	for (int i = 0; i < n; ++i) {
		int t = que.size();
		for (int j = 0; j < t; ++j) {
			long long d;
			int bi;
			tie(d,bi) = que.front();
			que.pop();
			for (auto it : graph[bi]) {
				if (dist[it.first] < dist[bi]+it.second) {
					dist[it.first] = dist[bi]+it.second;
					// printf("%d %d %lld\n",it.first,bi,dist[it.first]);
					que.push({dist[it.first],it.first});
				}
			}  
		}
		// printf("%d %lld <<<<<<\n",i,dist[n-1]);
	}
	for (;!que.empty();) {
		int t = que.size();
		for (int j = 0; j < t; ++j) {
			long long d;
			int bi;
			tie(d,bi) = que.front();
			que.pop();
			for (auto it : graph[bi]) {
				if (dist[it.first] == LLONG_MAX)continue;
				dist[it.first] = LLONG_MAX;
				que.push({dist[it.first],it.first});
			}  
		}
		// printf("%d %lld <<<<<<\n",i,dist[n-1]);
	}
	if (dist[n-1] == LLONG_MAX) {
		printf("-1");
	} else {
		printf("%lld",dist[n-1]);
	}
	return 0;
}