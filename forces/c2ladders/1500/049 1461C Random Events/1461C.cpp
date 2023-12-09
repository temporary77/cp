#include <bits/stdc++.h>
using namespace std;

stack<int> stck;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		scanf("%d%d",&n,&m);
		int r = 0;
		for (int i = 1; i <= n; ++i) {
			int a;
			scanf("%d",&a);
			if (a != i)r = i;
		}
		double curinverse = 1;
		for (int i = 0; i < m; ++i) {
			int l;
			double p;
			scanf("%d%lf",&l,&p);
			// printf("%d %lf\n",l,p);
			if (l >= r) {
				curinverse *= (1-p);
			}
		}
		if (r == 0)printf("1.000000\n");
		else printf("%lf\n",1-curinverse);
	}
	return 0;
}