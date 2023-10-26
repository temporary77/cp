#include <bits/stdc++.h>
using namespace std;

int arr[2501];
vector<pair<int,int>> graph[2501];
long long dist[2501][2501];
bool visited[2501][2501];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		for (int j = 0; j <= 2500; ++j)dist[i][j] = LLONG_MAX;
	}
	int x, y, z;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&x,&y,&z);
		--x; --y;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
	priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<tuple<long long,int,int>>> pq;
	dist[0][2500] = 0;
	pq.push({0,0,2500});
	long long ans = LLONG_MAX;
	for (;!pq.empty();) {
		int d, b, k;
		tie(d,b,k) = pq.top();
		pq.pop();
		if (visited[b][k])continue;
		//printf("%d %d %d\n",d,b,k);
		visited[b][k] = 1;
		if (b == n-1) {
			//ans = min(ans,dist[b][k]);
			ans = dist[b][k];
			break;
		}
		//printf("%d %d\n",b,dist[b][k]);
		int k1 = min(k,arr[b]);
		for (auto it : graph[b]) {
			if (dist[it.first][k1] > dist[b][k]+(it.second)*k1) {
				//printf("%d %d %d %d %d\n",it.first,b,dist[b][k],it.second,k1);
				dist[it.first][k1] = dist[b][k]+(it.second)*k1;
				pq.push({dist[it.first][k1],it.first,k1});
				//printf("%d\n",dist[it.first][k1]);
			}
		}
	}
	printf("%d",ans);
	return 0;
}