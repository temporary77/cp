#include <bits/stdc++.h>
using namespace std;

long long arr[400001];
bool sieve[1000001];

int main() {
	int n;
	scanf("%d",&n);
	long long max1 = LLONG_MIN;
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&arr[i]);
		max1 = max(max1,arr[i]);
	}
	sieve[1] = 1;
	for (long long i = 2; i <= sqrt(max1); ++i) {
		if (!sieve[i]) {
			for (long long j = i*i; j <= sqrt(max1); j += i) {
				sieve[j] = 1;
			}
		}
	}
	long long gcd = arr[0];
	for (int i = 1; i < n; ++i) {
		gcd = __gcd(gcd,arr[i]);
	}
	long long ans = 1;
	int cnt;
	for (int j = 2; j <= sqrt(gcd); ++j) {
		if (sieve[j])continue;
		if (!(gcd%j)) {
			cnt = 1;
			for (;gcd%j == 0; gcd /= j) {
				++cnt;
			}
			ans *= cnt;
		}
	}
	if (gcd > 1)ans *= 2;
	printf("%lld",ans);
	return 0;
}