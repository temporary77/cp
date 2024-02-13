#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
long long fac[100001];
long long inverse[50001];
long long inversefac[50001];

int main() {
	int n;
	scanf("%d",&n);
	inverse[1] = 1;
	for (int i = 2; i <= n/6; ++i) {
		inverse[i] = (mod-mod/i)*inverse[mod%i];
		inverse[i] %= mod;
	}
	fac[1] = 1;
	for (int i = 2; i <= n/3; ++i) {
		fac[i] = fac[i-1]*i;
		fac[i] %= mod;
	}
	inversefac[1] = 1;
	for (int i = 2; i <= n/6; ++i) {
		inversefac[i] = inversefac[i-1]*inverse[i];
		inversefac[i] %= mod;
	}
	long long ans = 1;
	for (int i = 0; i < n/3; ++i) {
		int arr[3];
		for (int j = 0; j < 3; ++j)scanf("%d",&arr[j]);
		sort(arr,arr+3);
		if (arr[0] == arr[1] && arr[0] == arr[2]) {
			ans *= 3;
		} else if (arr[0] == arr[1]) {
			ans *= 2;
		}
		ans %= mod;
	}
	ans *= fac[n/3];
	ans %= mod;
	ans *= inversefac[n/6];
	ans %= mod;
	ans *= inversefac[n/6];
	ans %= mod;
	printf("%lld\n",ans);
	return 0;
}