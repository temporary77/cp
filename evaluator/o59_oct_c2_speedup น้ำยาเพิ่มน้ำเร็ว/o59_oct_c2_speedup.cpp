#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph1[80001];
int pot[11];
bool ispot[80001];
long long dist[80001][9];
priority_queue<tuple<long long,int,int,int>, vector<tuple<long long,int,int,int>>, greater<tuple<long long,int,int,int>>> pq;

int main() {
	int n, m, l, q;
	scanf("%d%d%d%d",&n,&m,&l,&q);
	int a, b, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&w);
		graph1[a].push_back({b,w});
	}
	for (int i = 1; i <= l; ++i) {
		scanf("%d",&pot[i]);
		ispot[pot[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= q; ++j) {
			dist[i][j] = LLONG_MAX;
		}
	}
	dist[1][0] = 0;
	pq.push({0,1,0,0});
	long long ans;
	for (;!pq.empty();) {
		long long w;
		int ni, qi, ld;
		tie(w,ni,qi,ld) = pq.top();
		pq.pop();
		if (dist[ni][qi] < w)continue;
		//printf("%lld %d %d %d\n",w,ni,qi,ld);
		if (ni == n) {
			ans = dist[ni][qi];
			break;
		}
		for (auto it : graph1[ni]) {
			if (ispot[ni] && ld != ni && qi < q && dist[it.first][qi+1] > dist[ni][qi]+it.second/(1 << qi+1)) {
				dist[it.first][qi+1] = dist[ni][qi]+it.second/(1 << qi+1);
				pq.push({dist[it.first][qi+1],it.first,qi+1,ni});
			}
			if (dist[it.first][qi] > dist[ni][qi]+it.second/(1 << qi)) {
				dist[it.first][qi] = dist[ni][qi]+it.second/(1 << qi);
				pq.push({dist[it.first][qi],it.first,qi,ld});
			}
		}
	}
	printf("%lld",ans);
	return 0;
}