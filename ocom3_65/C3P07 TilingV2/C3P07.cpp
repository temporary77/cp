#include <bits/stdc++.h>
using namespace std;

long long dp[6][31];

/*
0  1  2  3  4  5  6  7  8  9

0  X  0  X  0  X
0  0  0  X  X  X
0  0  X  0  X  X

*/

vector<pair<int,int>> vctr[6] = {{{1,1},{2,1},{5,1}},{{0,1},{4,1}},{{0,1},{3,1}},{{2,1}},{{1,1}},{{0,1}}};

int main() {
	int t;
	scanf("%d",&t);
	int n;
	dp[0][0] = 1;
	for (int j = 1; j <= 30; ++j) {
		for (int k = 0; k < 6; ++k) {
			for (auto it : vctr[k]) {
				if (dp[k][j-1] == 0)break;
				dp[it.first][j] += dp[k][j-1]+it.second-1;
			}
			//printf("%d ",dp[k][j]);
		}
		//printf("\n");
	}
	for (int i = 0; i < t; ++i) {
		scanf("%d",&n);
		printf("%lld\n",dp[0][n]);
	}
	return 0;
}