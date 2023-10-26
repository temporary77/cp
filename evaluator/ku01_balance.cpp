#include <bits/stdc++.h>
using namespace std;

pair<pair<bool,int>,pair<bool,int>> graph[1001];

int ans = 0;

int dfs(int n) {
	int x, y;
	if (graph[n].first.first == 1) {
		x = graph[n].first.second;
	} else {
		x = dfs(graph[n].first.second);
	}
	if (graph[n].second.first == 1) {
		y = graph[n].second.second;
	} else {
		y = dfs(graph[n].second.second);
	}
	//printf("%d %d %d\n",x,n,y);
	ans += abs(x-y);
	return 2*max(x,y);
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if (a == 0) {
			graph[i].first = {0,b};
		} else if (a == 1) {
			graph[i].first = {1,b};
		}
		if (c == 0) {
			graph[i].second = {0,d};
		} else if (c == 1) {
			graph[i].second = {1,d};
		}
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}