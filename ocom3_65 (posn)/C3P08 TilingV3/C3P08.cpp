#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
long long dp[4][1001];

/*
0  1  2  3  4

0  X  0  X
0  0  X  X

*/

vector<pair<int,int>> vctr[4] = {{{0,1},{1,1},{2,1},{3,1}},{{2,1},{3,1}},{{1,1},{3,1}},{{0,1}}};

int main() {
	int n;
	scanf("%d",&n);
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (auto it : vctr[j]) {
				if (dp[j][i-1] == 0)break;
				dp[it.first][i] += dp[j][i-1]+it.second-1;
				dp[it.first][i] %= mod;
			}
		}
	}
	printf("%lld",dp[0][n]);
	return 0;
}