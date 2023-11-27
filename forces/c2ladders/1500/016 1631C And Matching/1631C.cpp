#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		if (n == 4 && k == 3) {
			printf("-1\n");
			continue;
		}
		int bits = n-1;
		if (k != n-1) {
			if (k != 0)printf("%d %d\n",k,bits);
			printf("%d %d\n",0,bits^k);
			for (int i = 1; i < (n >> 1); ++i) {
				if (i == k || i == (bits^k))continue;
				printf("%d %d\n",i,bits^i);
			}
		} else {
			printf("%d %d\n",bits^1,bits);
			printf("%d %d\n",0,1);
			printf("%d %d\n",2,bits^3);
			printf("%d %d\n",3,bits^2);
			for (int i = 4; i < (n >> 1); ++i) {
				printf("%d %d\n",i,bits^i);
			}		}
		// printf("---\n");
	}
	return 0;
}