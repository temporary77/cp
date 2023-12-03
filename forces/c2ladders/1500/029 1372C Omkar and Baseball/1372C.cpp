#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		bool alr = false;
		bool inseg = false;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int a;
			scanf("%d",&a);
			if (a != i) {
				if (alr) {
					ans = 2;
					continue;
				}
				if (!inseg) {
					inseg = true;
					ans = 1;
				}
			} else if (a == i) {
				if (inseg) {
					inseg = false;
					alr = true;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}