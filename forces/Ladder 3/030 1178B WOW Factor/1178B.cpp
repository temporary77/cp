#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	long long w1 = 0, wo = 0;
	long long ans = 0;
	for (int i = 1; i < str.size(); ++i) {
		if (str[i] == 'v' && str[i-1] == 'v') {
			++w1;
			ans += wo;
		} else if (str[i] == 'o') {
			wo += w1;
		}
	}
	printf("%lld",ans);
	return 0;
}