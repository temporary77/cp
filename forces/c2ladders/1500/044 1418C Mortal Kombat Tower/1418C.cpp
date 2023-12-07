#include <bits/stdc++.h>
using namespace std;

int dp[2][200001];
bool hard[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&hard[i]);
		}
		dp[0][0] = 1e9;
		dp[1][0] = 0;
		dp[0][1] = hard[1];
		dp[1][1] = 1e9;
		for (int i = 2; i <= n; ++i) {
			dp[0][i] = min(dp[1][i-1]+hard[i],dp[1][i-2]+hard[i-1]+hard[i]);
			dp[1][i] = min(dp[0][i-1],dp[0][i-2]);
		}
		// for (int i = 0; i <= n; ++i) {
		// 	printf("%d ",dp[0][i]);
		// }
		// printf("\n");
		// for (int i = 0; i <= n; ++i) {
		// 	printf("%d ",dp[1][i]);
		// }
		// printf("\n");
		printf("%d\n",min(dp[0][n],dp[1][n]));
	}
	return 0;
}