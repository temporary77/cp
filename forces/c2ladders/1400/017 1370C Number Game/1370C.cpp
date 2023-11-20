#include <bits/stdc++.h>
using namespace std;

const int P = sqrt(5e8);
vector<int> primes;
bool sieve[P+1];

bool isprime(int x) {
	if (x == 1)return false;
	for (auto it : primes) {
		if (it > sqrt(x))break;
		if (x%it == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	sieve[1] = true;
	for (int i = 2; i <= P; ++i) {
		if (!sieve[i]) {
			primes.push_back(i);
			for (int j = i*i; j <= P; j += i) {
				sieve[j] = true;
			}
		}
	}
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		if (n&1) {
			if (n == 1) {
				printf("FastestFinger\n");
			} else {
				printf("Ashishgup\n");
			}
		} else if (n%2 == 0 && n%4 != 0) {
			n /= 2;
			if (isprime(n)) {
				printf("FastestFinger\n");
			} else {
				printf("Ashishgup\n");
			}
		} else {
			for (;!(n&1);)n >>= 1;
			if (n == 1) {
				printf("FastestFinger\n");
			} else {
				printf("Ashishgup\n");
			}
		}
	}
	return 0;
}