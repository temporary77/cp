#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10001];
bool visited[400001];
pair<int,int> edges[400001];
vector<int> vctr;
int ans = INT_MIN;

void dfs(int n, int r, int cnt) {
	//printf("%d %d %d\n",r,n,cnt);
	if (n == r) {
		ans = max(ans,cnt);
		return;
	}
	for (auto it : graph[n]) {
		if (visited[it])continue;
		pair<int,int> e = edges[it];
		if (n != e.first) {
			swap(e.first,e.second);
		}
		visited[it] = 1;
		dfs(e.second,r,cnt+1);
		visited[it] = 0;		
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(i);
		graph[b].push_back(i);
		edges[i] = {a,b};
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (graph[i].size()%2) {
			++cnt;
			vctr.push_back(i);
		}
	}
	if (cnt == 0) {
		printf("%d",m);
		return 0;
	}
	for (auto it : vctr) {
		//printf("%d\n",it); 
		for (auto it2 : graph[it]) {
			pair<int,int> e = edges[it2];
			if (it != e.first) {
				swap(e.first,e.second);
			}
			visited[it2] = 1;
			dfs(e.second,it,1);
			visited[it2] = 0;
		}
	}
	printf("%d",ans);
	return 0;
}