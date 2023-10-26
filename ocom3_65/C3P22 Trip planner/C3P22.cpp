#include <bits/stdc++.h>
using namespace std;

int arr[1001];
vector<pair<pair<int,int>,int>> graph[1001][101];
int dist[1001][101];
bool visited[1001][101];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		for (int j = 0; j < 100; ++j) {
			graph[i][j].push_back({{i,j+1},arr[i]});
		}
	}
	int a, b, x;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&x);
		for (int j = 100; j >= x; --j) {
			graph[a][j].push_back({{b,j-x},0});
			graph[b][j].push_back({{a,j-x},0});
		}
	}
	int q;
	scanf("%d",&q);
	int c, s, e;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d",&c,&s,&e);
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k <= c; ++k) {
				dist[j][k] = INT_MAX;
				visited[j][k] = 0;
			}
		}
		dist[s][0] = 0;
		priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
		pq.push({0,{s,0}});
		int d;
		pair<int,int> b;
		for (;!pq.empty();) {
			tie(d,b) = pq.top();
			pq.pop();
			if (visited[b.first][b.second] == 1)continue;
			if (b.first == e && b.second == 0) {
				break;
			}
			visited[b.first][b.second] = 1;
			for (auto it : graph[b.first][b.second]) {
				//printf("%d %d %d %d %d ><><>\n",it.first.first,it.first.second,it.second,dist[it.first.first][it.first.second],dist[b.first][b.second]);
				if (dist[it.first.first][it.first.second] > dist[b.first][b.second]+it.second && visited[it.first.first][it.first.second] == 0 && it.first.second <= c) {
					dist[it.first.first][it.first.second] = dist[b.first][b.second]+it.second;
					//printf("%d <\n",dist[it.first.first][it.first.second]);
					pq.push({dist[it.first.first][it.first.second],{it.first.first,it.first.second}});
				}
			}
		}
		/*for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= c; ++j) {
				printf("%d ",dist[i][j]);
			}
			printf("\n");
		}*/
		if (dist[e][0] == INT_MAX)printf("impossible\n");
		else printf("%d\n",dist[e][0]);
	}
	return 0;
}