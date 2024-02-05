#include <bits/stdc++.h>
using namespace std;

bool arr[64];
bool brr[64];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		long long n, x;
		scanf("%lld%lld",&n,&x);
		int idx = -1;
		long long ni = n, xi = x;
		for (int i = 0; i < 64; ++i) {
			arr[i] = ni&1;
			ni /= 2;
			brr[i] = xi&1;
			xi /= 2;
			if (arr[i] && !brr[i]) {
				idx = i;
			}
		}
		long long m = (((n >> idx+1)+1) << idx+1);
		if (n == x)m = n;
		// printf("%lld %lld %lld\n",n,m,n&m);
		if ((n&m) != x) {
			printf("-1\n");
		} else {
			printf("%lld\n",m);
		}
	}
	return 0;
}

/*

001010
101010

*/