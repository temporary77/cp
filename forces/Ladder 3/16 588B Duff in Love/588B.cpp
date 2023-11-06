#include <bits/stdc++.h>
using namespace std;

bool sieve[1000005];

int main() {
	long long n;
	scanf("%lld",&n);
	long long ans = 1;
	sieve[1] = 1;
	for (long long i = 2; i <= 1e6; ++i) {
		if (!sieve[i]) {
			for (;n%(i*i) == 0;)n /= i;
			for (long long j = i*i; j <= 1e6; j += i) {
				sieve[j] = 1;
			}
		}
	}
	printf("%lld",n);
	return 0;
}