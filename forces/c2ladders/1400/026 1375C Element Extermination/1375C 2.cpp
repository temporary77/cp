#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int l, r;
		scanf("%d",&l);
		for (int i = 1; i < n-1; ++i) {
			scanf("%*d");
		}
		scanf("%d",&r);
		if (l < r) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}