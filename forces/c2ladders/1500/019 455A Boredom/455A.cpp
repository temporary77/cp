#include <bits/stdc++.h>
using namespace std;

// long long dp[2][100001];
long long dp[100001];
int cnt[100001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		++cnt[a];
	}
	dp[1] = cnt[1];
	for (int i = 2; i <= 100000; ++i) {
		// dp[0][i] = max(dp[1][i-1],dp[0][i-1]);
		// dp[1][i] = dp[0][i-1]+cnt[i]*(long long)i;
		dp[i] = max(dp[i-1],dp[i-2]+cnt[i]*(long long)i);
	}
	// printf("%lld\n",max(dp[0][100000],dp[1][100000]));
	printf("%lld\n",dp[100000]);
	return 0;
}