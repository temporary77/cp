#include <bits/stdc++.h>
using namespace std;

long long dp[2001][2001];
const int mod = 1e9+7;

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; ++i) {
		dp[1][i] = 1;
	}
	for (int i = 1; i < k; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] %= mod;
			for (int k = j; k <= n; k += j) {
				dp[i+1][k] += dp[i][j];
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += dp[k][i];
	}
	ans %= mod;
	printf("%lld",ans);
	return 0;
}