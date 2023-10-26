#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int c = 1;
		int l, r;
		int distl = 0, distr = 0;
		int pdl = 0, pdr = 0;
		int pl = 1, pr = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d",&l,&r);
			pdl = distl;
			pdr = distr;
			distl = min(pdl+abs(l-r)+abs(pl-r),pdr+abs(l-r)+abs(pr-r));
			distr = min(pdl+abs(l-r)+abs(pl-l),pdr+abs(l-r)+abs(pr-l));
			pl = l;
			pr = r;
			//printf("%d %d\n",distl,distr);
		}
		printf("%d\n",min(distl+n-l,distr+n-r)+n-1);
	}
	return 0;
}