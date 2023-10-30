#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[100001];
long long dist[100001];
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&c);
		graph[--a].push_back({--b,c});
	}
	fill(dist,dist+n,LLONG_MAX);
	dist[0] = 0;
	pq.push({0,0});
	for (;!pq.empty();) {
		int bi;
		long long d;
		tie(d,bi) = pq.top();
		pq.pop();
		if (d > dist[bi])continue;
		for (auto it : graph[bi]) {
			if (dist[it.first] > dist[bi]+it.second) {
				dist[it.first] = dist[bi]+it.second;
				pq.push({dist[it.first],it.first});
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%lld ",dist[i]);
	}
	return 0;
}