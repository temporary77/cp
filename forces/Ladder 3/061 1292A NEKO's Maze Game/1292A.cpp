#include <bits/stdc++.h>
using namespace std;

bool grid[2][100001];
int cnt = 0;

int main() {
	int n, q;
	scanf("%d%d",&n,&q);
	int r, c;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d",&r,&c);
		--r; --c;
		if (!grid[r][c]) {
			if (c > 0 && grid[r^1][c-1])++cnt;
			if (grid[r^1][c])++cnt;
			if (c < n-1 && grid[r^1][c+1])++cnt;
		} else {
			if (c > 0 && grid[r^1][c-1])--cnt;
			if (grid[r^1][c])--cnt;
			if (c < n-1 && grid[r^1][c+1])--cnt;
		}
		grid[r][c] ^= 1;
		if (cnt == 0) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}