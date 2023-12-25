#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
long long dp[200011];
long long cnt[10];

int main() {
	cin.tie(NULL);
	cnt[0] = 1;
	dp[0] = 1;
	for (int i = 1; i <= 200010; ++i) {
		long long temp = cnt[9];
		for (int j = 9; j >= 1; --j) {
			cnt[j] = cnt[j-1];
		}
		cnt[0] = temp;
		cnt[1] += temp;
		cnt[1] %= mod;
		dp[i] = dp[i-1]+temp;
		dp[i] %= mod;
	}
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		cin >> str;
		int m;
		scanf("%d",&m);
		long long ans = 0;
		for (auto it : str) {
			ans += dp[m+it-'0'];
			ans %= mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}