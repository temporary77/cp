#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		if (n <= 3) {
			printf("-1\n");
			continue;
		}
		for (int i = 2; i <= n; i += 2) {
			printf("%d ",i);
		}
		if (n&1) {
			printf("%d %d %d ",n-4,n,n-2);
			for (int i = n-6; i >= 1; i -= 2) {
				printf("%d ",i);
			}
		} else {
			printf("%d %d ",n-3,n-1);
			for (int i = n-5; i >= 1; i -= 2) {
				printf("%d ",i);
			}
		}
		printf("\n");
	}
	return 0;
}