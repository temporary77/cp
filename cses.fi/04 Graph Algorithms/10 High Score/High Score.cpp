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
					if (dist[it.first] != LLONG_MIN) {
						
					}
					dist[it.first] = dist[bi]+it.second;
					que.push({dist[bi]+it.second,it.first});
				}
			}  
		}
	}
	for (int i = 0; i < n; ++i) {
		int t = que.size();
		for (int j = 0; j < t; ++j) {
			long long d;
			int bi;
			tie(d,bi) = que.front();
			if (bi == n-1)goto g;
			que.pop();
			for (auto it : graph[bi]) {
				if (dist[it.first] < dist[bi]+it.second) {
					dist[it.first] = dist[bi]+it.second;
					que.push({dist[bi]+it.second,it.first});
				}
			}  
		}
	}
	printf("%lld",dist[n-1]);
	return 0;
	g:;
	printf("-1");
	return 0;
}