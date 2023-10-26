#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
int bl[200001][18];
int height[200001];
int ans[200001];

void findheight(int node, int pa, int h) {
	height[node] = h;
	if (pa != -1)bl[node][0] = pa;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		findheight(it,node,h+1);
	}
	return;
}

int calcsum(int node, int pa) {
	int res = ans[node];
	for (auto it : graph[node]) {
		if (it == pa)continue;
		res += calcsum(it,node);
	}
	ans[node] = res;
	return res;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	findheight(1,-1,0);
	for (int k = 1; k <= floor(log2(n)); ++k) {
		for (int i = 2; i <= n; ++i) {
			bl[i][k] = bl[bl[i][k-1]][k-1];
		}
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		int ai = a, bi = b;
		if (height[a] != height[b]) {
			if (height[b] < height[a]) {
				swap(a,b);
				swap(ai,bi);
			}
			for (int dist = height[b]-height[a]; dist > 0; dist -= dist&-dist) {
				b = bl[b][(int)floor(log2(dist&-dist))];
			}
		}
		// printf("%d %d\n",ai,bi);
		if (a == b) {
			++ans[bi];
			// printf("%d %d\n",bi,ai);
			if (bl[ai][0] != 0) {
				--ans[bl[ai][0]];
			}
			continue;
		}
		int cap1 = floor(log2(n));
		for (;a != b;) {
			int l = -1;
			int r = cap1;
			for (;;) {
				if (l >= r)break;
				int m = (l+r+1)/2;
				if (bl[a][m] == bl[b][m]) {
					r = m-1;
				} else {
					l = m;
				}
			}
			if (l == -1) {
				l = 0;
			}
			a = bl[a][l];
			b = bl[b][l];
			cap1 = l-1;
		}
		++ans[ai];
		++ans[bi];
		--ans[a];
		if (bl[a][0] != 0) {
			--ans[bl[a][0]];
		}
		// printf("%d %d %d\n",ai,bi,a);
	}
	calcsum(1,-1);
	for (int i = 1; i <= n; ++i) {
		printf("%d ",ans[i]);
	}
	return 0;
}