#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[50001];
int arr[50001];
pair<int,int> dist[50001];
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

int main() {
	int n, m, l;
	scanf("%d%d%d",&n,&m,&l);
	int s, t;
	scanf("%d%d",&s,&t);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		scanf("%d%d%d",&a,&b,&w);
		graph[a].push_back({b,w});
	}
	for (int i = 1; i <= n; ++i) {
		dist[i] = {INT_MAX,-1};
	}
	pq.push({0,0,s});
	int ans = -1;
	for (;!pq.empty();) {
		int w, o, b;
		tie(w,o,b) = pq.top();
		pq.pop();
		if (arr[b] == o+1 && o <= l) {
			++o;
		}
		if (o <= dist[b].second) {
			continue;
		}
		//printf("%d %d %d\n",w,o,b);
		dist[b] = {w,o};
		if (o == l && b == t) {
			ans = dist[b].first;
			break;
		}
		for (auto it : graph[b]) {
			pq.push({dist[b].first+it.second,o,it.first});
		}
	}
	printf("%d",ans);
	return 0;
}