#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	if (n > m)swap(n,m);
	for (int i = 1; i <= m; ++i) {
		dp[i][i] = 0;
	}
	if (n == m)goto g;
	int a, b;
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= m; ++j) {
			dp[i][j] = INT_MAX;
			for (int k = 1; k <= j/2; ++k) {
				if(i <= k)a = dp[i][k];
				else a = dp[k][i];
				if(i <= j-k)b = dp[i][j-k];
				else b = dp[j-k][i];
				dp[i][j] = min(dp[i][j],a+b);
			}
			for (int k = 1; k <= i/2; ++k) {
				if(j <= k)a = dp[j][k];
				else a = dp[k][j];
				if(j <= i-k)b = dp[j][i-k];
				else b = dp[i-k][j];
				dp[i][j] = min(dp[i][j],a+b);
			}
			++dp[i][j];
			// printf("%d %d %d\n",dp[i][j],i,j);
		}
	}
	g:;
	printf("%d",dp[n][m]);
	return 0;
}