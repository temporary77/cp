#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[11];
bool visited[11];
vector<pair<int,int>> graph[11];
int ans = INT_MAX;
int k;

void dfs(int x, int cnt, int dist) {
	//for (int i = 0; i < cnt; ++i)printf(" ");
	//printf("%d %d ",x,dist);
	if (cnt == k) {
		ans = min(ans,dist+abs(arr[0].first-arr[x].first)+abs(arr[0].second-arr[x].second));
		//printf("%d %d\n",ans,abs(arr[0].first-arr[x].first)+abs(arr[0].second-arr[x].second));
		return;
	}
	//printf("\n");
	visited[x] = 1;
	for (auto it : graph[x]) {
		if (visited[it.first] == 0) {
			dfs(it.first,cnt+1,dist+it.second);
		}
	}
	visited[x] = 0;
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&arr[0].first,&arr[0].second);
	--arr[0].first;
	--arr[0].second;
	scanf("%d",&k);
	for (int i = 1; i <= k; ++i) {
		scanf("%d%d",&arr[i].first,&arr[i].second);
		--arr[i].first;
		--arr[i].second;
	}
	int d;
	for (int i = 0; i <= k; ++i) {
		for (int j = i+1; j <= k; ++j) {
			d = abs(arr[i].first-arr[j].first)+abs(arr[i].second-arr[j].second);
			graph[i].push_back({j,d});
			graph[j].push_back({i,d});
		}
	}
	/*for (int i = 0; i <= k; ++i)printf("%d ",arr[i].first);
	printf("\n");
	for (int i = 0; i <= k; ++i)printf("%d ",arr[i].second);
	printf("\n");*/
	dfs(0,0,0);
	printf("%d",ans);
	return 0;
}