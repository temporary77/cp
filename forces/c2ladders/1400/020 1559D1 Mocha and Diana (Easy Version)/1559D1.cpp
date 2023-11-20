#include <bits/stdc++.h>
using namespace std;

int disjoint[2][1001];
int sz[2][1001];
vector<pair<int,int>> vctr;

int parent(int x, int k) {
	for (;x != disjoint[k][x];) {
		x = disjoint[k][x];
	}
	return x;
}

int main() {
	int n, m1, m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for (int i = 1; i <= n; ++i) {
		disjoint[0][i] = i;
		disjoint[1][i] = i;
		sz[0][i] = 1;
		sz[1][i] = 1;
	}
	for (int i = 0; i < m1; ++i) {
		int u, v;
		scanf("%d%d",&u,&v);
		int pu = parent(u,0);
		int pv = parent(v,0);
		if (sz[0][pu] > sz[0][pv]) {
			swap(pu,pv);
			swap(u,v);
		}
		disjoint[0][pu] = pv;
		disjoint[0][u] = pv;
		disjoint[0][v] = pv;
		sz[0][pv] += sz[0][pu];
	}
	for (int i = 0; i < m2; ++i) {
		int u, v;
		scanf("%d%d",&u,&v);
		int pu = parent(u,1);
		int pv = parent(v,1);
		if (sz[1][pu] > sz[1][pv]) {
			swap(pu,pv);
			swap(u,v);
		}
		disjoint[1][pu] = pv;
		disjoint[1][u] = pv;
		disjoint[1][v] = pv;
		sz[1][pv] += sz[1][pu];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			int pi0 = parent(i,0);
			int pj0 = parent(j,0);
			if (pi0 == pj0)continue;
			int pi1 = parent(i,1);
			int pj1 = parent(j,1);
			if (pi1 == pj1)continue;
			vctr.push_back({i,j});
			if (sz[0][pi0] > sz[0][pj0]) {
				swap(pi0,pj0);
			}
			disjoint[0][pi0] = pj0;
			sz[0][pj0] += sz[0][pi0];
			if (sz[1][pi1] > sz[1][pj1]) {
				swap(pi1,pj1);
			}
			disjoint[1][pi1] = pj1;
			sz[1][pj1] += sz[1][pi1];
		}
	}
	printf("%d\n",vctr.size());
	for (auto it : vctr) {
		printf("%d %d\n",it);
	}
	return 0;
}