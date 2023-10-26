#include <bits/stdc++.h>
using namespace std;

int dp[200002];
int arr[200002];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		dp[n] = 0;
		for (int i = n-1; i >= 0; --i) {
			if (n-i <= arr[i]) {
				dp[i] = min(n-i,dp[i+1]+1);
			} else {
				dp[i] = min(dp[i+arr[i]+1],dp[i+1]+1);
			}
			// printf("%d %d %d %d\n",i,dp[i],i+arr[i]+1,dp[i+arr[i]+1]);
		}
		printf("%d\n",dp[0]);
	}
	return 0;
}