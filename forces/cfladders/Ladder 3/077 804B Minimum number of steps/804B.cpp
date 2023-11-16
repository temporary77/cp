#include <bits/stdc++.h>
using namespace std;

long long cal[1000001];
const int mod = 1e9+7;

int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	cal[0] = 1;
	for (int i = 1; i <= 1000000; ++i) {
		cal[i] = cal[i-1] << 1;
		cal[i] %= mod;
	}
	long long ans = 0;
	int cur = 0;
	for (auto it : str) {
		if (it == 'a') {
			++cur;
		} else if (it == 'b') {
			ans += cal[cur]-1;
			ans %= mod;
		}
	}
	printf("%lld",ans);
	return 0;
}