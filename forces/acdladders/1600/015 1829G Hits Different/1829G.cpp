#include <bits/stdc++.h>
using namespace std;

long long dp[1000001];

int main() {
	int x = 1;
	for (int i = 1; x <= 1e6; x += ++i) {
		dp[x] = x*(long long)x;
		int y = x+i;
		for (int j = i; y <= 1e6; y += ++j) {
			dp[y] = dp[y-j]+y*(long long)y; 
		}
	}
	x = 1;
	for (int i = 1; x <= 1e6; x += i++) {
		int y = x+i+1;
		for (int j = i+1; y <= 1e6; y += ++j) {
			dp[y] += dp[y-j];
		}
	}
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
	return 0;
}