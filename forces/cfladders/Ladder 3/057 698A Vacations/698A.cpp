#include <bits/stdc++.h>
using namespace std;

int dp[101][3];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		int k;
		scanf("%d",&k);
		if (k&1) {
			dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
		} else {
			dp[i][1] = INT_MAX;
		}
		if (k&2) {
			dp[i][0] = min(dp[i-1][1],dp[i-1][2]);
		} else {
			dp[i][0] = INT_MAX;
		}
		dp[i][2] = min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
	}
	printf("%d",min(min(dp[n][0],dp[n][1]),dp[n][2]));
	return 0;
}