#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int ksack[1000001];
int brr[1001];

int main() {
	for (int i = 2; i <= 1000; ++i)dp[i] = INT_MAX;
	for (int i = 1; i <= 1000; ++i) {
		for (int j = i; j >= 1; --j) {
			if (i+i/j > 1000)break;
			dp[i+i/j] = min(dp[i+i/j],dp[i]+1);
		}
	}
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		fill(ksack,ksack+k+1,0);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&brr[i]);
		}
		for (int i = 0; i < n; ++i) {
			int c;
			scanf("%d",&c);
			for (int j = k; j-dp[brr[i]] >= 0; --j) {
				ksack[j] = max(ksack[j],ksack[j-dp[brr[i]]]+c);
			}
		}
		printf("%d\n",ksack[k]);
	}
	return 0;
}