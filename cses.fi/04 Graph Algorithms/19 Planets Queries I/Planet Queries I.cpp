#include <bits/stdc++.h>
using namespace std;

int bl[200001][31];

int betterlog2(int x) {
	int res = -1;
	int k = 1;
	for (;k <= x;) {
		k *= 2;
		++res;
	}
	return res;
}

int main() {
	int n, q;
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&bl[i][0]);
	}
	for (int i = 1; i <= 30; ++i) {
		for (int j = 1; j <= n; ++j) {
			bl[j][i] = bl[bl[j][i-1]][i-1];
		}
	}
	int x, k;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d",&x,&k);
		for (int j = k; j > 0; j ^= (j&-j)) {
			x = bl[x][betterlog2(j&-j)];
		}
		printf("%d\n",x);
	}
	return 0;
}