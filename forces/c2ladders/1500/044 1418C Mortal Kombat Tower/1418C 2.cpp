#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int ans;
		scanf("%d",&ans);
		int cur = 0;
		for (int i = 1; i < n; ++i) {
			int a;
			scanf("%d",&a);
			if (a) {
				++cur;
			} else {
				ans += cur/3;
				cur = 0;
			}
		}
		ans += cur/3;
		printf("%d\n",ans);
	}
	return 0;
}