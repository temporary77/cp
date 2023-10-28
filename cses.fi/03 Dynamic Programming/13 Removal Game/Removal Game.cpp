#include <bits/stdc++.h>
using namespace std;

long long dp[5001][5001];
int arr[5001];
// long long qs[5001];

// long long query(int a, int b) {
// 	if (a == 0)return qs[b];
// 	return qs[b]-qs[a-1];
// }

int main() {
	int n;
	scanf("%d",&n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		dp[i][i] = arr[i];
		sum += arr[i];
		// if (i == 0)qs[i] = arr[i];
		// else qs[i] = qs[i-1]+arr[i];
	}
	// here dp[i][j] straights up represents max points for first to play
	// for (int k = 1; k < n; ++k) {
	// 	for (int i = 0; i < n-k; ++i) {
	// 		if (dp[i][i+k-1] < dp[i+1][i+k]) {
	// 			dp[i][i+k] = query(i,i+k-1)-dp[i][i+k-1]+arr[i+k];
	// 		} else {
	// 			dp[i][i+k] = query(i+1,i+k)-dp[i+1][i+k]+arr[i];
	// 		}
	// 	}
	// }

	// dp[i][j] represents lead (score1 - score2)
	for (int k = 1; k < n; ++k) {
		for (int i = 0; i < n-k; ++i) {
			dp[i][i+k] = max(arr[i]-dp[i+1][i+k],arr[i+k]-dp[i][i+k-1]);
			//printf("%d %d %lld\n",i,i+k,dp[i][i+k]);
		}
	}
	printf("%lld",(sum+dp[0][n-1]) >> 1);
	return 0;
}