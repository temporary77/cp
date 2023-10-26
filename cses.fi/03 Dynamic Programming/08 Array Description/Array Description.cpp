#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
long long dp[100001][102];
int arr[100001];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	if (arr[0] != 0) {
		dp[0][arr[0]] = 1;
	} else {
		for (int i = 1; i <= m; ++i) {
			dp[0][i] = 1;
		}
	}
	for (int i = 1; i < n; ++i) {
		if (arr[i] != 0) {
			dp[i][arr[i]] = dp[i-1][arr[i]-1]+dp[i-1][arr[i]]+dp[i-1][arr[i]+1];
			dp[i][arr[i]] %= mod;
		} else {
			for (int j = 1; j <= m; ++j) {
				dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
				dp[i][j] %= mod;
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= m; ++i) {
		ans += dp[n-1][i];
		ans %= mod;
	}
	printf("%lld",ans);
	return 0;
}