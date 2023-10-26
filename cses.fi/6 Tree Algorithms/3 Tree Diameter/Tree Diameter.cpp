#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
int ans = 0;

int dfs(int node, int pa) {
	int max1 = 0;
	int max2 = 0;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		int height = dfs(it,node);
		if (height >= max1) {
			max2 = max1;
			max1 = height;
		} else if (height > max2) {
			max2 = height;
		}
	}
	//printf("%d %d %d\n",node,max1,max2);
	ans = max(ans,max1+max2);
	return max1+1;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1,-1);
	printf("%d",ans);
	return 0;
}