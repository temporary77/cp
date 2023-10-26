#include <bits/stdc++.h>
using namespace std;

long long dp[6][1001];

/*
0  1  2  3  4  5  6  7  8  9

0  X  X  0  X  0
0  X  0  0  X  X
0  0  0  X  X  X
0  0  X  X  X  0

*/

vector<pair<int,int>> vctr[6] = {{{0,1},{1,1},{2,1},{3,1},{4,1}},{{0,1},{3,1}},{{0,1},{5,1}},{{0,1},{1,1}},{{0,1}},{{2,1}}};

int main() {
	int n;
	scanf("%d",&n);
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 6; ++j) {
			for (auto it : vctr[j]) {
				if (dp[j][i-1] == 0)break;
				dp[it.first][i] += dp[j][i-1]*it.second;
			}
		}
	}
	printf("%lld",dp[0][n]);
	return 0;
}