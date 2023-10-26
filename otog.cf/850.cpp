#include <bits/stdc++.h>
using namespace std;

struct data {
	int p, c, s;
	bool operator < (const data &rhs) const {
		if (p != rhs.p) {
			return p < rhs.p;
		} else {
			return 
		}
	}	
};

int arr[1001];
vector<pair<int,int>> graph[1001];
priority_queue<data, vector<data>, greater<data>> pq;
int visited[1001];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	int a, b, x;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&x);
		graph[a].push_back({b,x});
		graph[b].push_back({a,x});
	}
	int q;
	scanf("%d",&q);
	int cap, s, e;
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d%d",&cap,&s,&e);
		for (auto it : graph[e]) {
			if (it.second <= cap) {
				pq.push({it.second*arr[it.first],conit.sed,0,it.first});
			}
		}
		for (;!pq.empty();) {
			int cst = get<0>(pq.top());
			int dist = get<1>(pq.top());
			int prev = get<2>(pq.top());
			int end = get<3>(pq.top());
			pq.pop();
			if (visited[end] == i)continue;
			visited[end] = i;

		}
	}
	return 0;
}