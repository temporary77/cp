#include <bits/stdc++.h>
using namespace std;

long long dp[100];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	if (m == 1) {
		printf("1");
		return 0;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i] += dp[i-1];
		if (i-m >= 0)dp[i] += dp[i-m];
	}
	printf("%lld",dp[n]);
	return 0;
}