#include <bits/stdc++.h>
using namespace std;

int arr[1001], brr[1001];
int dp[1001];

int main() {
	int n, w;
	scanf("%d%d",&n,&w);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d",&brr[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = w; j >= 0; --j) {
			if (j >= arr[i])dp[j] = max(dp[j],dp[j-arr[i]]+brr[i]);
		}
	}
	printf("%d",dp[w]);
	return 0;
}