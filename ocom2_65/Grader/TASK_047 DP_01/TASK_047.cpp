#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("test_input.txt","r",stdin);
	long long n, m, c;
	scanf("%lld%lld%lld",&n,&m,&c);
	long long arr[n];
	for (int i = 1; i <= n; ++i) {
		scanf("%lld",&arr[i]);
	}
	long long req[m], max1 = INT_MIN;
	for (int i = 0; i < m; ++i) {
		scanf("%lld",&req[i]);
		max1 = max(max1,req[i]);
	}
	long long f[max1+1];
	f[0] = 0;
	for (int i = 1; i <= max1; ++i) {
		f[i] = LONG_LONG_MAX;
		for (int j = 1; j <= i; ++j) {
			f[i] = min(f[i],f[j-1]+(arr[i]-arr[j])*(arr[i]-arr[j]));
		}
		f[i] += c;
	}
	for (int i = 0; i < m; ++i) {
		printf("%lld\n",f[req[i]]);
	}
	return 0;
}