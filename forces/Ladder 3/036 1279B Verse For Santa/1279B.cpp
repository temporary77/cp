#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, s;
		scanf("%d%d",&n,&s);
		int k;
		int max1 = 0;
		int cur = 0;
		int ans = 0;
		bool check = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&k);
			if (ans)continue;
			if (k > max1) {
				max1 = k;
				cur = i;
			}
			if (s-k < 0) {
				ans = cur;
			}
			s -= k;
		}
		printf("%d\n",ans);
	}
	return 0;
}