#include <bits/stdc++.h>
using namespace std;

int disjoint[500001];
int sz[500001];

int parent(int x) {
	for (;x != disjoint[x];) {
		x = disjoint[x];
	}
	return x;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		disjoint[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int k;
		scanf("%d",&k);
		int x;
		int prev = -1;
		for (int j = 0; j < k; ++j) {
			scanf("%d",&x);
			--x;
			if (prev != -1) {
				int px = parent(x);
				int pp = parent(prev);
				if (px != pp) {
					if (sz[px] > sz[pp])swap(px,pp);
					disjoint[x] = pp;
					disjoint[px] = pp;
					sz[pp] += sz[px];
				}
			}
			prev = x;
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ",sz[parent(i)]);
	}
	return 0;
}