#include <bits/stdc++.h>
using namespace std;

long long dp[201];

int main() {
	cin.tie(nullptr);
	int n;
	scanf("%d",&n);
	string str, str2;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		str = 'x'+str;
		for (int j = 1; j < str.size(); ++j) {
			dp[j] = 0;
			for (int k = 1; k <= j; ++k) {
				str2 = str.substr(j-k+1,k);
				if (stoll(str2) > INT_MAX)break;
				dp[j] = max(dp[j],dp[j-k]+stoll(str2));
			}
		}
		printf("%lld\n",dp[str.size()-1]);
	}
	return 0;
}