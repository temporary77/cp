#include <bits/stdc++.h>
using namespace std;

int dp[10][2][2];

int main() {
	cin.tie(NULL);
	string str;
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		cin >> str;
		int n = str.size();
		for (int i = 0; i <= n; ++i) {
			dp[i][0][0] = 0;
			dp[i][0][1] = 0;
			dp[i][1][0] = 0;
			dp[i][1][1] = 0;
		}
		dp[n][0][0] = 1;
		for (int i = n-1; i >= 0; --i) {
			for (int j = 0; j < 10; ++j) {
				for (int k = 0; k < 10; ++k) {
					if ((j+k)%10 == str[i]-'0') {
						dp[i][(j+k)/10][0] += dp[i+1][0][0];
						dp[i][(j+k)/10][1] += dp[i+1][1][0];
					} else if ((j+k+1)%10 == str[i]-'0') {
						dp[i][(j+k+1)/10][0] += dp[i+1][0][1];
						dp[i][(j+k+1)/10][1] += dp[i+1][1][1];
					}
				}
			}
		}
		printf("%d\n",dp[0][0][0]-2);
	}
	return 0;
}