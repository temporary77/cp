#include <bits/stdc++.h>
using namespace std;

int dp[1001][11][1025];
const int mod = 1e9+7;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	if ((n*m)%2) {
		printf("0");
		return 0;
	}
	dp[0][n-1][(1 << n)-1] = 1;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < (1 << n); ++k) {
				if (k&(1 << j)) {
					if (j > 0)dp[i][j][k] = dp[i][j-1][k^(1 << j)];
					else dp[i][j][k] = dp[i-1][n-1][k^(1 << j)];
					dp[i][j][k] %= mod;
					if (j > 0) {
						if (k&(1 << j-1)) {
							dp[i][j][k] += dp[i][j-1][k^(1 << j-1)];
							dp[i][j][k] %= mod;
						}
					}
				} else {
					if (j > 0)dp[i][j][k] = dp[i][j-1][k^(1 << j)];
					else dp[i][j][k] = dp[i-1][n-1][k^(1 << j)];
					dp[i][j][k] %= mod;
				}
			}
		}
	}
	printf("%d",dp[m][n-1][(1 << n)-1]);
	return 0;
}