#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];

int main() {
	cin.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
	int n = str1.size();
	int m = str2.size();
	// dp[i][j] stores min dist s.t. everything up to i-1 j-1 is done
	// or dp[i][j] stores min dist s.t. everything up to but i and j is done
	// (results in same dp)
	dp[0][0] = 0;
	for (int i = 1; i <= m; ++i) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = i;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
			}
		}
	}
	// for (int i = 0; i <= n; ++i) {
	// 	for (int j = 0; j <= m; ++j) {
	// 		printf("%d ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// for (int i = 0; i <= n; ++i) {
	// 	for (int j = 0; j <= m; ++j) {
	// 		printf("%d ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	printf("%d",dp[n][m]);
	return 0;
}