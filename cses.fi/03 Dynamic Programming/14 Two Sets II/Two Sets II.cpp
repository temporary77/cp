#include <bits/stdc++.h>
using namespace std;

int dp[62626];
const int mod = 1e9+7;

int main() {
	int n;
	scanf("%d",&n);
	if (n%4 == 1 || n%4 == 2) {
		printf("0");
		return 0;
	}
	long long trgtsum = n*(n+1)/4;
	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = trgtsum; j >= i; --j) {
			if (dp[j-i]) {
				dp[j] += dp[j-i];
				dp[j] %= mod;
			}
			//printf("%d %d\n",j,dp[j]);
		}
	}
	printf("%d",dp[trgtsum]);
	return 0;
}