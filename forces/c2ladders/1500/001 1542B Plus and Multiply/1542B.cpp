#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		long long n, a, b;
		scanf("%lld%lld%lld",&n,&a,&b);
		long long cur = 1;
		for (;;) {
			if (cur > n)break;
			if (!((n-cur)%b)) {
				printf("Yes\n");
				goto g;
			}
			cur *= a;
			if (a == 1)break;
		}
		printf("No\n");
		g:;
	}
	return 0;
}