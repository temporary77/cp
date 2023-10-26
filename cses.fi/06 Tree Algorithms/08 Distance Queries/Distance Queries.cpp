#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
int bl[200001][18];
int height[200001];

void findheight(int node, int pa, int h) {
	height[node] = h;
	// printf(">> %d %d\n",node,pa);
	if (pa != -1)bl[node][0] = pa;
	//printf("%d %d\n",node,h);
	for (auto it : graph[node]) {
		if (it == pa)continue;
		findheight(it,node,h+1);
	}
	return;
}

int main() {
	int n, q;
	scanf("%d%d",&n,&q);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	findheight(1,-1,0);
	for (int k = 1; k <= floor(log2(n)); ++k) {
		for (int i = 2; i <= n; ++i) {
			if (i == 4) {
				// printf(">>>>%d %d %d %d\n",i,k,bl[i][k-1],bl[bl[i][k-1]][k-1]);
			}
			bl[i][k] = bl[bl[i][k-1]][k-1];
		}
	}
	for (int i = 0; i < q; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		// printf("%d %d %d %d\n",a,height[a],b,height[b]);
		int ans = 0;
		if (height[a] != height[b]) {
			if (height[b] < height[a]) {
				swap(a,b);
			}
			//printf("%d %d %d\n",a,b,height[b]-height[a]);
			ans += height[b]-height[a];
			for (int dist = height[b]-height[a]; dist > 0; dist -= dist&-dist) {
				// printf("%d %d <\n",b,(int)log2(dist&-dist));
				b = bl[b][(int)log2(dist&-dist)];
			}
		}
		// printf("%d %d %d %d\n",a,height[a],b,height[b]);
		int cap1 = floor(log2(n));
		//printf(">> %d %d\n",a,b);
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
			ans += (1 << l+1);
		}
		printf("%d\n",ans);
	}


	return 0;
}