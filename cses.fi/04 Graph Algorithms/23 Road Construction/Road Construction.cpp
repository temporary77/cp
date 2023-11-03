#include <bits/stdc++.h>
using namespace std;

int disjoint[100001];
int size1[100001];
int max1;
int cnt;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		disjoint[i] = i;
		size1[i] = 1;
	}
	max1 = 1;
	cnt = n;
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		--a; --b;
		int pa = a, pb = b;
		for (;pa != disjoint[pa];) {
			pa = disjoint[pa];
		}
		for (;pb != disjoint[pb];) {
			pb = disjoint[pb];
		}
		if (pa == pb)goto g;
		if (size1[pa] < size1[pb]) {
			swap(pa,pb);
		}
		disjoint[pb] = pa;
		disjoint[b] = pa;
		size1[pa] += size1[pb];
		max1 = max(max1,size1[pa]);
		--cnt;
		g:;
		printf("%d %d\n",cnt,max1);
	}





	return 0;
}