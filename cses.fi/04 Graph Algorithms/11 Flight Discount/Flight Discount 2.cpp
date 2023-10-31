#include <bits/stdc++.h>
using namespace std;

vector<pair<int,long long>> graph1[100001];
vector<pair<int,long long>> graph2[100001];
long long dist1[100001];
long long dist2[100001];
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	long long c;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%lld",&a,&b,&c);
		--a; --b;
		graph1[a].push_back({b,c});
		graph2[b].push_back({a,c});
	}
	pq.push({0,0});
	fill(dist1,dist1+n,LLONG_MAX);
	dist1[0] = 0;
	for (;!pq.empty();) {
		long long d;
		int bi;
		tie(d,bi) = pq.top();
		pq.pop();
		if (dist1[bi] < d)continue;
		// printf("%lld %d\n",dist1[bi],bi);
		for (auto it : graph1[bi]) {
			if (dist1[it.first] > dist1[bi]+it.second) {
				dist1[it.first] = dist1[bi]+it.second;
				pq.push({dist1[it.first],it.first});
			}
		}
	}
	pq.push({0,n-1});
	fill(dist2,dist2+n,LLONG_MAX);
	dist2[n-1] = 0;
	for (;!pq.empty();) {
		long long d;
		int bi;
		tie(d,bi) = pq.top();
		pq.pop();
		if (dist2[bi] < d)continue;
		// printf("%lld %d\n",dist2[bi],bi);
		for (auto it : graph2[bi]) {
			if (dist2[it.first] > dist2[bi]+it.second) {
				dist2[it.first] = dist2[bi]+it.second;
				pq.push({dist2[it.first],it.first});
			}
		}
	}
	long long ans = LLONG_MAX;
	for (int i = 0; i < n; ++i) {
		for (auto it : graph1[i]) {
			if (dist1[i] == LLONG_MAX || dist2[it.first] == LLONG_MAX)continue;
			ans = min(ans,dist1[i]+it.second/2+dist2[it.first]);
		}
	}
	printf("%lld",ans);
	return 0;
}