#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m;
	scanf("%lld%lld",&n,&m);
	long long min1 = max(0LL,n-m*2);
	long long minc = 0;
	for (;;) {
		if (m <= 0)break;
		m -= minc;
		++minc;
	}
	printf("%lld %lld",min1,n-minc);
	return 0;
}