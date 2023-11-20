#include <bits/stdc++.h>
using namespace std;

set<int> st[200001];
bool die[200001];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int cnt = n;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d",&u,&v);
		st[u].insert(v);
		if (!die[u]) {
			if (*st[u].rbegin() > u) {
				--cnt;
				die[u] = true;
			}
		}
		st[v].insert(u);
		if (!die[v]) {
			if (*st[v].rbegin() > v) {
				--cnt;
				die[v] = true;
			}
		}
	}
	int q;
	scanf("%d",&q);
	for (int qi = 0; qi < q; ++qi) {
		int k;
		scanf("%d",&k);
		if (k == 1) {
			int u, v;
			scanf("%d%d",&u,&v);
			st[u].insert(v);
			if (!die[u]) {
				if (*st[u].rbegin() > u) {
					--cnt;
					die[u] = true;
				}
			}
			st[v].insert(u);
			if (!die[v]) {
				if (*st[v].rbegin() > v) {
					--cnt;
					die[v] = true;
				}
			}
		} else if (k == 2) {
			int u, v;
			scanf("%d%d",&u,&v);
			st[u].erase(v);
			if (die[u]) {
				if (st[u].empty() || *st[u].rbegin() < u) {
					++cnt;
					die[u] = false;
				}
			}
			st[v].erase(u);
			if (die[v]) {
				if (st[v].empty() || *st[v].rbegin() < v) {
					++cnt;
					die[v] = false;
				}
			}
		} else if (k == 3) {
			printf("%d\n",cnt);
		}
	}
	return 0;
}