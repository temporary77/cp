#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
int height[2][200001];

int precompute(int node, int pa) {
	int max1 = 0;
	int max2 = 0;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		int height = precompute(it,node);
		if (height >= max1) {
			max2 = max1;
			max1 = height;
		} else if (height > max2) {
			max2 = height;
		}
	}
	height[0][node] = max1;
	height[1][node] = max2;
	return max1+1;
}

void dfs(int node, int pa, int curmax) {
	//printf("%d %d %d\n",node,pa,curmax);
	for (auto it : graph[node]) {
		if (it == pa)continue;
		if (height[0][it]+1 == height[0][node]) {
			dfs(it,node,max(curmax,height[1][node])+1);
		} else {
			dfs(it,node,max(curmax,height[0][node])+1);			
		}
	}
	height[0][node] = max(height[0][node],curmax);
	return;
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
	precompute(1,-1);
	dfs(1,-1,0);
	for (int i = 1; i <= n; ++i) {
		printf("%d ",height[0][i]);
	}
	return 0;
}