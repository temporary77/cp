#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int,int>> graph[1001];
int srr[1001];
long long dist[1001][1001];
// int cur[1001];
priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<tuple<long long,int,int>>> pq;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		scanf("%d%d",&n,&m);
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d%d%d",&u,&v,&w);
			graph[u].push_back({v,w});
			graph[v].push_back({u,w});
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&srr[i]);
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dist[i][j] = LLONG_MAX;
			}
			// cur[i] = INT_MAX;
		}
		dist[1][1] = 0;
		// cur[1] = srr[1];
		pq.push({0,1,1});
		long long ans = LLONG_MAX;
		for (;pq.size();) {
			long long d;
			int si, bi;
			tie(d,si,bi) = pq.top();
			pq.pop();
			// printf("%lld %d %d\n",d,si,bi);
			if (d > dist[bi][si])continue;
			if (bi == n)ans = min(ans,d);
			for (auto it : graph[bi]) {
				int ns = srr[si] > srr[it.f] ? it.f : si;
				// printf("%d %d %d %lld %lld %d %d\n",bi,it.f,it.s,dist[it.f][ns],dist[bi][si]+srr[si]*it.s,srr[ns],cur[it.f]);
				if (dist[it.f][ns] > dist[bi][si]+srr[si]*it.s) {// && srr[ns] <= cur[it.f]) {
					dist[it.f][ns] = dist[bi][si]+srr[si]*it.s;
					// cur[it.f] = srr[ns];
					pq.push({dist[it.f][ns],ns,it.f});
				}
			}
		}
		for(;pq.size();)pq.pop();
		for (int i = 1; i <= n; ++i) {
			graph[i].clear();
		}
		printf("%lld\n",ans);
	}
	return 0;
}