#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[200011];

int main() {
	cin.tie(NULL);
	for (int i = 0; i <= 9; ++i) {
		dp[i] = 1;
	}
	for (int i = 10; i <= 200010; ++i) {
		dp[i] = dp[i-9]+dp[i-10];
		dp[i] %= mod;
	}
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		cin >> str;
		int m;
		scanf("%d",&m);
		int ans = 0;
		for (auto it : str) {
			ans += dp[m+it-'0'];
			ans %= mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}