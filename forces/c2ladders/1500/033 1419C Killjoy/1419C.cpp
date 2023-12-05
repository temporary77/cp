#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, x;
		scanf("%d%d",&n,&x);
		int ttl = 0;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			if (a == x)++cnt;
			ttl += a;
		}
		if (cnt == n) {
			printf("0\n");
		} else if (cnt >= 2) {
			printf("1\n");
		} else if (cnt == 1) {
			printf("1\n");
		} else {
			if (ttl%n == 0 && ttl/n == x) {
				printf("1\n");
			} else {
				printf("2\n");
			}
		}
	}
	return 0;
}