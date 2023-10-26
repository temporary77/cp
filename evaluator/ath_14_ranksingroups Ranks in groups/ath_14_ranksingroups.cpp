#include <bits/stdc++.h>
using namespace std;


int main() {
	int T;
	scanf("%d",&T);
	for (int t = 0; t < T; ++t) {
		int n, l;
		scanf("%d%d",&n,&l);
		vector<int> vctr[100001] = {{}};
		int pa[100001] = {0};
		for (int i = 1; i <= n; ++i) {
			vctr[i].push_back(i);
			pa[i] = i;
		}
		for (int i = 0; i < l; ++i) {
			int k, a, b;
			scanf("%d",&k);
			if (k == 1) {
				scanf("%d%d",&a,&b);
				for (;a != pa[a];) {
					a = pa[a];
				}
				for (;b != pa[b];) {
					b = pa[b];
				}
				if (vctr[a].size() < vctr[b].size()) {
					swap(a,b);
				}
				for (auto it : vctr[b]) {
					vctr[a].push_back(it);
					auto idx1 = upper_bound(vctr[a].begin(),vctr[a].end()-1,it);
					rotate(idx1,--vctr[a].end(),vctr[a].end());
				}
				pa[b] = a;
			} else if (k == 2) {
				scanf("%d",&a);
				int qa = a;
				for (;a != pa[a];) {
					a = pa[a];
				}
				printf("%d\n",vctr[a].size()-(lower_bound(vctr[a].begin(),vctr[a].end(),qa)-vctr[a].begin()));
			}
		}
	}
	return 0;
}