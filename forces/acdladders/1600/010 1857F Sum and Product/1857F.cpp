#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			++mp[a];
		}
		int q;
		scanf("%d",&q);
		for (int qi = 0; qi < q; ++qi) {
			long long x, y;
			scanf("%lld%lld\n",&x,&y);
			long long d = x*x-4*y;
			if (d < 0) {
				printf("0 ");
			} else if (d == 0) {
				long long ans = mp.find(x/2) == mp.end() ? 0 : mp[x/2]*(long long)(mp[x/2]-1)/2;
				printf("%lld ",ans);
			} else {
				double a = (x-sqrt(d))/2;
				double b = (x+sqrt(d))/2;
				if (a != floor(a) || b != floor(b)) {
					printf("0 ");
					continue;
				}
				int akey = a;
				int bkey = b;
				// printf("[%d %d]",akey,bkey);
				if (mp.find(akey) == mp.end() || mp.find(bkey) == mp.end()) {
					printf("0 ");
					continue;
				}
				printf("%lld ",mp[akey]*(long long)mp[bkey]);
			}
		}
		printf("\n");
		mp.clear();
	}
	return 0;
}