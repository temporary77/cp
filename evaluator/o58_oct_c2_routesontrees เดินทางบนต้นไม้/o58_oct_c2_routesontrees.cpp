#include <bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int>>> graph[200001][6];
int dist[200001][6];
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

int main() {
	int n, m, k;
	scanf("%d%d%d",&n,&m,&k);
	int uj, vj, hj;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&uj,&vj,&hj);
		for (int j = 0; j <= k; ++j) {
			if (hj < 0) {
				if (hj < -100) {
					if (j == 0)continue;
					graph[uj][j].push_back({0,{vj,j-1}});
				} else {
					graph[uj][j].push_back({0,{vj,j}});
				}
			} else {
				graph[uj][j].push_back({hj,{vj,j}});
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dist[i][j] = INT_MAX;
			if (j != 0)graph[i][j].push_back({0,{i,j-1}});
		}
	}
	dist[1][k] = 0;
	pq.push({0,{1,k}});
	int p, t, ki;
	for (;!pq.empty();) {
		p = pq.top().first;
		t = pq.top().second.first;
		ki = pq.top().second.second;
		pq.pop();
		if (dist[t][ki] < p)continue;
		//printf("{%d,%d} %d\n",t,ki,p);
		if (t == n && ki == 0)break;
		for (auto it : graph[t][ki]) {
			//if (t == 3 && ki == 0)printf("%d %d %d\n",it);
			if (dist[it.second.first][it.second.second] > dist[t][ki]+it.first) {
				dist[it.second.first][it.second.second] = dist[t][ki]+it.first;
				pq.push({dist[it.second.first][it.second.second],it.second});
			}
		}
	}
	if (dist[n][0] == INT_MAX) {
		printf("-1");
	} else {
		printf("%d",dist[n][0]);
	}
	return 0;
}