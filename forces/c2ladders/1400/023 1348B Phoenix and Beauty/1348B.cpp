#include <bits/stdc++.h>
using namespace std;

unordered_map<int,bool> mp;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			mp[a] = true;
		}
		if (mp.size() > k) {
			printf("-1\n");
			goto g;
		}
		printf("%d\n",k*n);
		for (int i = 0; i < n; ++i) {
			for (auto it : mp) {
				printf("%d ",it.first);
			}
			for (int j = 0; j < k-mp.size(); ++j) {
				printf("1 ");
			}
		}
		printf("\n");
		g:;
		mp.clear();
	}
	return 0;
}