#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10000];
int dist[10000];
map<int,int> weight;

int main() {
	//freopen("test_input.txt","r",stdin);
	int n, s, t;
	scanf("%d%d%d",&n,&s,&t);
	int m, a, b, d;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d",&a,&d,&m);
		weight[a] = d;
		for (int j = 0; j < m; ++j) {
			scanf("%d",&b);
			graph[a].push_back({b});
		}
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for (int i = 0; i < n; ++i) {
		dist[i] = INT_MAX;
	}
	pq.push({0,s});
	dist[s] = 0;
	int w;
	for (int i = 1; i < n; ++i) {
		b = pq.top().second;
		w = pq.top().first;
		pq.pop();
		//printf(">>>>>>> %d %d\n",b,w);
		for (auto it : graph[b]) {
			//printf("consider %d and %d+%d\n",dist[it], dist[b], weight[b]-weight[it]);
			if (dist[it] > dist[b]+weight[b]-weight[it] && weight[b] > weight[it]) {
				dist[it] = dist[b]+weight[b]-weight[it];
				pq.push({dist[it],it});
			}
		}
		/*for (int i = 0; i < n; ++i) {
			printf("%d %d\n",i+1,dist[i]);
		}*/
	}
	/*for (int i = 0; i < n; ++i) {
		if (dist[i] == INT_MAX)printf("%d -1\n",i);
		else printf("%d %d\n",i,dist[i]);
	}
	printf("\n");*/
	if (dist[t] == INT_MAX) {
		printf("-1");
	} else {
		printf("%d",dist[t]);
	}
	return 0;
}