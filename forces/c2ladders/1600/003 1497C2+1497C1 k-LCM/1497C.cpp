#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		for (int i = 0; i < k-3; ++i) {
			printf("1 ");
		}
		n -= (k-3);
		k = 3;
		if ((n%4)&1) {
			printf("1 %d %d\n",(n-1)/2,(n-1)/2);
		} else if (!(n%4)) {
			printf("%d %d %d\n",n/2,n/4,n/4);
		} else if (n%4 == 2) {
			printf("2 %d %d\n",(n-2)/2,(n-2)/2);
		}
	}
	return 0;
}