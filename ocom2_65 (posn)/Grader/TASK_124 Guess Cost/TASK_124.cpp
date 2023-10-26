#include <bits/stdc++.h>
using namespace std;

int arr[301];
int dp[301][301];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < n-1; ++i) {
		dp[i][i] = arr[i];
		dp[i][i+1] = arr[i]+arr[i+1];
	}
	dp[n-1][n-1] = arr[n-1];
	for (int i = 2; i < n; ++i) {
		for (int j = 0; j < n-i; ++j) {
			dp[j][j+i] = INT_MAX;
			for (int k = j+1; k < j+i; ++k) {
				dp[j][j+i] = min(dp[j][j+i],arr[k]+max(dp[j][k-1],dp[k+1][j+i]));
			}
		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}*/
	printf("%d",dp[0][n-1]);
	return 0;
}