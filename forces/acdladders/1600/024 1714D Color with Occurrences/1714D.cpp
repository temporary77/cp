#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int,int>> graph[105];
int dist[105];
int parent[105];
int edge[105];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
stack<pair<int,int>> ans;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	string str2;
	for (int ti = 0; ti < t; ++ti) {
		cin >> str;
		for (int i = 1; i < str.size(); ++i) {
			graph[i].push_back({i-1,-1});
		}
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			cin >> str2;
			if (str2.size() > str.size())continue;
			for (int j = 0; j <= str.size()-str2.size(); ++j) {
				if (string(str.begin()+j,str.begin()+str2.size()+j) == str2) {
					graph[j].push_back({str2.size()+j,i+1});
				}
			}
		}
		for (int i = 0; i <= str.size(); ++i) {
			dist[i] = INT_MAX;
		}
		dist[0] = 0;
		pq.push({0,0});
		parent[0] = -1;
		for (;pq.size();) {
			int d, b;
			tie(d,b) = pq.top();
			pq.pop();
			if (d > dist[b])continue;
			if (b == str.size())break;
			// printf("%d %d\n",d,b);
			for (auto it : graph[b]) {
				if (dist[it.f] > dist[b]+(it.s == -1 ? 0 : 1)) {
					dist[it.f] = dist[b]+(it.s == -1 ? 0 : 1);
					parent[it.f] = b;
					edge[it.f] = it.s;
					// printf("%d reached from %d using %d\n",it.f,b,it.s);
					pq.push({dist[it.f],it.f});
				}
			}
		}
		int x = str.size();
		if (dist[x] == INT_MAX) {
			printf("-1\n");
			goto g;
		}
		for (;parent[x] != -1;) {
			if (edge[x] != -1)ans.push({edge[x],parent[x]+1});
			x = parent[x];
		}
		printf("%d\n",ans.size());
		for (;ans.size();) {
			printf("%d %d\n",ans.top());
			ans.pop();
		}
		g:;
		for (;pq.size();)pq.pop();
		for (int i = 0; i < str.size(); ++i) {
			graph[i].clear();
		}
	}
	return 0;
}