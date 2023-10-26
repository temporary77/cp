#include <bits/stdc++.h>
using namespace std;

int bj[200001][18];
vector<int> graph[200001];
int height[200001];

void dfs(int node, int pa, int h) {
	height[node] = h;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		dfs(it,node,h+1);
	}
	return;
}

int main() {
	int n, q;
	scanf("%d%d",&n,&q);
	for (int i = 2; i <= n; ++i) {
		int a;
		scanf("%d",&a);
		bj[i][0] = a;
		graph[a].push_back(i);
	}
	dfs(1,-1,0);
	for (int i = 1; i <= floor(log2(n)); ++i) {
		for (int j = 2; j <= n; ++j) {
			bj[j][i] = bj[bj[j][i-1]][i-1];
		}
	}
	for (int i = 0; i < q; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		if (height[a] < height[b]) {
			for (int dist = height[b]-height[a]; dist > 0; dist -= dist&-dist) {
				b = bj[b][(int)log2(dist&-dist)];
			}
		}
		if (height[a] > height[b]) {
			for (int dist = height[a]-height[b]; dist > 0; dist -= dist&-dist) {
				a = bj[a][(int)log2(dist&-dist)];
			}
		}
		//printf("%d %d %d %d\n",a,b,height[a],height[b]);
		for (;a != b;) {
			int l = -1;
			int r = floor(log2(n));
			for (;;) {
				if (l >= r) {
					break;
				}
				int m = (l+r+1)/2;
				if (bj[a][m] == bj[b][m]) {
					r = m-1;
				} else {
					l = m;
				}
			}
			if (l == -1)l = 0;
			a = bj[a][l];
			b = bj[b][l];
		}
		printf("%d\n",a);
	}
	return 0;
}