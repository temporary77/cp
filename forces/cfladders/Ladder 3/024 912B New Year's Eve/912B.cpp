#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, k;
	scanf("%lld%lld",&n,&k);
	if (k == 1) {
		printf("%lld",n);
	} else {
		int a = 0;
		for (; n > 0; ++a) {
			n >>= 1;
		}
		printf("%lld",((long long)1 << a)-1);
	}

	return 0;
}