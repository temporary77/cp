#include <bits/stdc++.h>
using namespace std;

int sieve[100001];

int main() {
	int n;
	scanf("%d",&n);
	int idx = 0;
	for (int i = 2; i*i <= n; ++i) {
		if (!sieve[i]) {
			++idx;
			sieve[i] = idx;
			for (int j = i*i; j <= n; j += i) {
				sieve[j] = idx;
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (!sieve[i]) {
			++idx;
			printf("%d ",idx);
		} else {
			printf("%d ",sieve[i]);
		}
	}
	return 0;
}