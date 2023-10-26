#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[1000];
bool visited[1000];
int dist[1000];

int main() {
	freopen("test_input.txt","r",stdin);
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&w);
		graph[--a].push_back({--b,w});
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for (int i = 0; i < n; ++i) {
		dist[i] = INT_MAX;
	}
	pq.push({0,0});
	dist[0] = 0;
	for (int i = 1; i < n; ++i) {
		b = pq.top().second;
		w = pq.top().first;
		pq.pop();
		//printf(">>>>>>> %d %d\n",b,w);
		visited[b] = 1;
		for (auto it : graph[b]) {
			//printf("consider %d and %d+%d\n",dist[it.first], dist[b], it.second);
			if (dist[it.first] > dist[b]+it.second && visited[it.first] == 0) {
				dist[it.first] = dist[b]+it.second;
				pq.push({dist[it.first],it.first});
			}
		}
		/*for (int i = 0; i < n; ++i) {
			printf("%d %d\n",i+1,dist[i]);
		}*/
	}
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n",i+1,dist[i]);
	}
	return 0;
}