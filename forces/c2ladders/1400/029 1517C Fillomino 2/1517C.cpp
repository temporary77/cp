#include <bits/stdc++.h>
using namespace std;

int grid[501][501];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&grid[i][i]);
	}
	for (int i = 0; i < n; ++i) {
		bool passed = false;
		for (int j = 0; i+j < n; ++j) {
			if (grid[i+j][j] == i+1) {
				passed = true;
				continue;
			}
			if (!passed) {
				grid[i+j+1][j] = grid[i+j][j];
			} else {
				grid[i+j][j-1] = grid[i+j][j];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			printf("%d ",grid[i][j]);
		}
		printf("\n");
	}
	return 0;
}