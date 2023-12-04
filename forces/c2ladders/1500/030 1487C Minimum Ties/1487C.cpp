#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int max1 = (n*(n-1)/2)/n;
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				if (j-i <= max1) {
					printf("1 ");
				} else if (n+i-j <= max1) {
					printf("-1 ");
				} else {
					printf("0 ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}