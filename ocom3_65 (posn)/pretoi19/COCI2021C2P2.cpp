#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[1001];
vector<pair<int,double>> graph[1001];
priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
bool visited[1001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d",&arr[i].first,&arr[i].second);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			graph[i].push_back({j,sqrt(pow(arr[i].first-arr[j].first,2)+pow(arr[i].second-arr[j].second,2))});
			graph[j].push_back({i,sqrt(pow(arr[i].first-arr[j].first,2)+pow(arr[i].second-arr[j].second,2))});
		}
	}
	pq.push({0,0});
	double w;
	int b;
	double ans = 0;
	int t = 0;
	for (;t < n;) {
		w = pq.top().first;
		b = pq.top().second;
		pq.pop();
		if (visited[b] == 1)continue;
		visited[b] = 1;
		ans = max(ans,w);
		++t;
		for (auto it : graph[b]) {
			if (visited[it.first] == 0) {
				pq.push({it.second,it.first});
			}
		}
	}
	printf("%.7lf",ans/2);
	return 0;
}