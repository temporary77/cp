#include <bits/stdc++.h>
using namespace std;

int arr[100001];
vector<int> graph[100001];
int max1[100001];
int ans = 0;

void dfs(int node, int pa) {
	if (max1[node] > arr[node]) {
		printf("%d\n",node);
		++ans;
	}
	for (auto it : graph[node]) {
		if (it == pa)continue;
		dfs(it,node);
	}
	return;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		max1[i] = -1;
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		max1[a] = max(max1[a],arr[b]);
	}
	dfs(0,-1);
	printf("%d",ans);
	return 0;
}