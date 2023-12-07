#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
	int n;
	scanf("%d",&n);
	long long fac = 1;
	for (int i = 1; i <= n; ++i) {
		fac *= i;
		fac %= mod;
	}
	long long pow = 1;
	for (int i = 1; i < n; ++i) {
		pow *= 2;
		pow %= mod;
	}
	printf("%lld\n",(fac-pow+mod)%mod);
	return 0;
}