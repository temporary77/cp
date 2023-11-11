#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	long long ans = 0;
	long long cur = 0;
	for (auto it = str.rbegin(); it != str.rend(); ++it) {
		if (*it == 'b') {
			++cur;
		} else if (*it == 'a') {
			ans += cur;
			ans %= mod;
			cur *= 2;
			cur %= mod;
		}
	}
	printf("%lld",ans);
	return 0;
}