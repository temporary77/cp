#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[1<<19];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<int> apple;
int dist[1<<19];

int main() {
	int n, s;
	scanf("%d%d",&n,&s);
	int w;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&w);
		int k;
		int p = 0, c = 0;
		for (int j = 0; j < s; ++j) {
			scanf("%d",&k);
			if (k == 1) {
				c += 1<<j;
			} else if (k == -1) {
				p += 1<<j;
			}
		}
		graph[p].push_back({c,w});
		apple.push_back(p);
	}
	for (int i = 0; i < 1<<s; ++i) {
		dist[i] = INT_MAX;
		for (int j = 0; j < s; ++j) {
			if (i&(1<<j)) {
				graph[i].push_back({i^(1<<j),0});
			}
		}
	}
	pq.push({0,0});
	dist[0] = 0;
	int b;
	int ans = INT_MIN;
	for (;!pq.empty();) {
		tie(w,b) = pq.top();
		pq.pop();
		if (dist[b] < w)continue;
		for (auto it : graph[b]) {
			if (dist[it.first] > dist[b]+it.second) {
				dist[it.first] = dist[b]+it.second;
				pq.push({dist[it.first],it.first});
			}
		}
	}

	for (auto it : apple) {
		if (dist[it] != INT_MAX) {
			ans = max(ans,dist[it]);
		}
	}
	printf("%d",ans);
	return 0;
}