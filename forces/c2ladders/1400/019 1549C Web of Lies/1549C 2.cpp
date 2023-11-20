#include <bits/stdc++.h>
using namespace std;

int killer[200001];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int cnt = n;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d",&u,&v);
		if (u > v)swap(u,v);
		if (killer[u] == 0) {
			--cnt;
		}
		++killer[u];
	}
	int q;
	scanf("%d",&q);
	for (int qi = 0; qi < q; ++qi) {
		int k;
		scanf("%d",&k);
		if (k == 1) {
			int u, v;
			scanf("%d%d",&u,&v);
			if (u > v)swap(u,v);
			if (killer[u] == 0) {
				--cnt;
			}
			++killer[u];
		} else if (k == 2) {
			int u, v;
			scanf("%d%d",&u,&v);
			if (u > v)swap(u,v);
			--killer[u];
			if (killer[u] == 0) {
				++cnt;
			}
		} else if (k == 3) {
			printf("%d\n",cnt);
		}
	}
	return 0;
}