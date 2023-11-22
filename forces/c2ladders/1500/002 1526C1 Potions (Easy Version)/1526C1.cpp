#include <bits/stdc++.h>
using namespace std;

long long dp[2001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)dp[i] = -1e18;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		for (int j = n; j >= 1; --j) {
			if (dp[j-1]+a >= 0)dp[j] = max(dp[j],dp[j-1]+a);
		}
		for (int i = 0; i <= n; ++i) {
			printf("%lld ",dp[i]);
		}
		printf("\n");
	}
	for (int i = n; i >= 0; --i) {
		if (dp[i] >= 0) {
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}