#include <bits/stdc++.h>
using namespace std;

int arr[200001];
vector<int> graph[200001];
bool visited[200001];

bool check = false;

void dfs(int node, int pa) {
	visited[node] = true;
	// printf("%d %d\n",node,pa);
	for (auto it : graph[node]) {
		if (visited[it]) {
			if (it != pa)check = true;
			continue;
		}
		dfs(it,node);
	}
	return;
}

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&arr[i]);
		}
		for (int i = 1; i <= n; ++i) {
			if (arr[i] > i && arr[arr[i]] == i)continue;
			graph[arr[i]].push_back(i);
			graph[i].push_back(arr[i]);
		}
		int selfcycles = 0;
		int strings = 0;
		fill(visited+1,visited+n+1,false);
		for (int i = 1; i <= n; ++i) {
			if (!visited[i]) {
				check = false;
				dfs(i,-1);
				// printf(">> %d %d\n",check,i);
				if (check) {
					++selfcycles;
				}
				else ++strings;
			}
		}
		printf("%d %d\n",selfcycles+(strings > 0 ? 1 : 0),selfcycles+strings);
		for (int i = 1; i <= n; ++i) {
			graph[i].clear();
		}
	}
	return 0;
}