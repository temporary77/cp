#include <bits/stdc++.h>
using namespace std;

pair<int,int> ans[1000001];
long long dp[1501][1501];

int main() {
	int x = 0;
	for (int i = 1; i <= 1500; ++i) {
		for (int j = 1; j <= i; ++j) {
			++x;
			if (x > 1e6)break;
			int k = i-j+1;
			ans[x] = {k,j};
			dp[k][j] = dp[k-1][j]+dp[k][j-1]-dp[k-1][j-1]+x*(long long)x;
		}
		if (x > 1e6)break;
	}
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		printf("%lld\n",dp[ans[n].first][ans[n].second]);
	}
	return 0;
}