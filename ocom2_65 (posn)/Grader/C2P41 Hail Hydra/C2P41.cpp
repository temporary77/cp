#include <bits/stdc++.h>
using namespace std;

int arr[8][8];
int ans;
bool col[8] = {0,0,0,0,0,0,0,0}, diag1[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, diag2[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void recursion(int r, int sum) {
	if (r == 8) {
		ans = max(ans,sum);
		return;
	}
	for (int i = 0; i < 8; ++i) {
		if (col[i] == 0 && diag1[r+i] == 0 && diag2[r-i+8] == 0) {
			col[i] = 1;
			diag1[r+i] = 1;
			diag2[r-i+8] = 1;
			recursion(r+1,sum+arr[r][i]);
			col[i] = 0;
			diag1[r+i] = 0;
			diag2[r-i+8] = 0;
		}
	}
	return;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int waste = 0; waste < n; ++waste) {
		ans = INT_MIN;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				scanf("%d",&arr[i][j]);
			}
		}
		recursion(0,0);
		printf("%d\n",ans);
	}

	return 0;
}