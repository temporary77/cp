#include <bits/stdc++.h>
using namespace std;

int arr[20];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		long long n;
		int s;
		scanf("%lld%d",&n,&s);
		int r;
		for (int i = 0; i < 20; ++i) {
			arr[i] = n%10;
			n /= 10;
			if (n == 0) {
				r = i;
				break;
			}
		}
		int ttl = 0;
		int idx = r;
		for (;;) {
			if (ttl > s)break;
			ttl += idx[r];
			--idx;
		}
		for (int j = r; j >= 0; --j) {
			printf("%d",arr[r]);
		}
		printf("\n");
	}
	return 0;
}