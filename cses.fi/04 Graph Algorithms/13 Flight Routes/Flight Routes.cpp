#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[100001];
priority_queue<long long> dist[100001];
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
stack<long long> stck;

int main() {
	int n, m, k;
	scanf("%d%d%d",&n,&m,&k);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&c);
		--a; --b;
		graph[a].push_back({b,c});
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			dist[i].push(LLONG_MAX);
		}
	}
	dist[0].push(0);
	dist[0].pop();
	pq.push({0,0});
	for (;!pq.empty();) {
		long long d;
		int bi;
		tie(d,bi) = pq.top();
		pq.pop();
		if (d > dist[bi].top())continue;
		// printf("%lld %d\n",d,bi);
		for (auto it : graph[bi]) {
			if (dist[it.first].top() > d+it.second) {
				dist[it.first].push(d+it.second);
				dist[it.first].pop();
				// printf("%lld %d <<\n",d+it.second,it.first);
				pq.push({d+it.second,it.first});
			}
		}
	}
	for (;!dist[n-1].empty();) {
		stck.push(dist[n-1].top());
		dist[n-1].pop();
	}
	for (;!stck.empty();) {
		printf("%lld ",stck.top());
		stck.pop();
	}
	return 0;
}