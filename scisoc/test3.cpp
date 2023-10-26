#include <bits/stdc++.h>
using namespace std;

int arr[10001], dp[10001];

int main() {
	int n, k;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
	}
	scanf("%d",&k);
	dp[1] = arr[1];
	if (k < n) n == k;
	for (int i = 2; i <= n; ++i) {
		dp[i] = arr[i];
		for (int j = i-1; j >= 1 && j >= i-k; --j) {
			dp[i] = max(dp[i],dp[j]+arr[i-j]);
		}
	}
	printf("%d",dp[k]);
}