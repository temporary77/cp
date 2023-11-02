#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[100001];
long long dist[100001];
long long cnt[100001];
int min1[100001];
int max1[100001];
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
const int mod = 1e9+7;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&c);
		graph[a].push_back({b,c});
	}
	fill(dist,dist+n+1,LLONG_MAX);
	fill(min1,min1+n+1,INT_MAX);
	fill(max1,max1+n+1,INT_MIN);
	dist[1] = 0;
	pq.push({0,1});
	cnt[1] = 1;
	min1[1] = 0;
	max1[1] = 0;
	for (;!pq.empty();) {
		long long d;
		int bi;
		tie(d,bi) = pq.top();
		pq.pop();
		if (d > dist[bi])continue;
		// printf("%lld %d <<<\n",d,bi);
		// for (int i = 1; i <= n; ++i) {
		// 	printf("%d ",min1[i]);
		// }
		// printf("\n");
		if (bi == n) {
			printf("%lld %lld %d %d",dist[n],cnt[n],min1[n],max1[n]);
			return 0;
		}
		for (auto it : graph[bi]) {
			// printf("%lld %lld+%d\n",dist[it.first],dist[bi],it.second);
			if (dist[it.first] >= dist[bi]+it.second) {
				if (dist[it.first] == dist[bi]+it.second) {
					// printf("%lld %d %d <-\n",dist[it.first],bi,it.first);
					cnt[it.first] += cnt[bi];
					cnt[it.first] %= mod;
					min1[it.first] = min(min1[it.first],min1[bi]+1);
					max1[it.first] = max(max1[it.first],max1[bi]+1);
				} else {
					// printf("%lld %lld %d %d <---\n",dist[it.first],dist[bi]+it.second,bi,it.first);
					cnt[it.first] = cnt[bi];
					min1[it.first] = min1[bi]+1;
					max1[it.first] = max1[bi]+1;
					dist[it.first] = dist[bi]+it.second;
					pq.push({dist[it.first],it.first});
				}
			}
		}
	}
	return 0;
}