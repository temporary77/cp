#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[100001];
long long dist[2][100001];
priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<tuple<long long,int,int>>> pq;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&c);
		--a; --b;
		graph[a].push_back({b,c});
		// graph[b].push_back({a,c});
	}
	fill(dist[0],dist[0]+n,LLONG_MAX);
	fill(dist[1],dist[1]+n,LLONG_MAX);
	dist[0][0] = 0;
	pq.push({0,0,0});
	for (;!pq.empty();) {
		int bi, mode;
		long long d;
		tie(d,bi,mode) = pq.top();
		pq.pop();
		if (dist[mode][bi] < d)continue;
		if (bi == n-1) {
			printf("%lld",dist[mode][bi]);
			return 0;
		}
		for (auto it : graph[bi]) {
			if (!mode) {
				if (dist[1][it.first] > dist[0][bi]+(it.second)/2) {
					dist[1][it.first] = dist[0][bi]+(it.second)/2;
					pq.push({dist[1][it.first],it.first,1});
				}
			}
			if (dist[mode][it.first] > dist[mode][bi]+it.second) {
				dist[mode][it.first] = dist[mode][bi]+it.second;
				pq.push({dist[mode][it.first],it.first,mode});
			}
		}
	}
	return 0;
}