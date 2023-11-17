#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		cin >> str;
		long long ans = 0;
		int cur = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == '?' || str[i]-'0' == (i&1)) {
				++cur;
			} else {
				ans += (long long)cur*(cur+1)/2;
				cur = 0;
			}
		}
		ans += (long long)cur*(cur+1)/2;
		cur = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == '?' || str[i]-'0' != (i&1)) {
				++cur;
			} else {
				ans += (long long)cur*(cur+1)/2;
				cur = 0;
			}
		}
		ans += (long long)cur*(cur+1)/2;
		cur = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == '?') {
				++cur;
			} else {
				ans -= (long long)cur*(cur+1)/2;
				cur = 0;
			}
		}
		ans -= (long long)cur*(cur+1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}