#include <bits/stdc++.h>
using namespace std;

int arr[2001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int ttl = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
			ttl ^= arr[i];
		}
		int cur = 0;
		int cur2 = 0;
		if (ttl == 0) {
			printf("YES\n");
			goto g;
		}
		for (int i = 0; i < n-1; ++i) {
			cur ^= arr[i];
			if (cur == ttl) {
				for (int j = i+1; j < n-1; ++j) {
					cur2 ^= arr[j];
					if (cur2 == cur) {
						printf("YES\n");
						goto g;
					}
				}
				break;
			}
		}
		printf("NO\n");
		g:;
	}
	return 0;
}