#include <bits/stdc++.h>
using namespace std;

int disjoint[100001];
int height[100001];
int cnt;
vector<int> vctr;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 1; i <= n; ++i) {
		disjoint[i] = i;
	}
	cnt = n;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		int pa = a, pb = b;
		for (;pa != disjoint[pa];) {
			pa = disjoint[pa];
		}
		for (;pb != disjoint[pb];) {
			pb = disjoint[pb];
		}
		if (pa == pb)continue;
		if (height[pb] > height[pa])swap(pa,pb);
		disjoint[pb] = pa;
		disjoint[b] = pa;
		if (height[pa] == height[pb])++height[pa];
		--cnt;
	}
	if (cnt > 1) {
		// for (int i = 1; i <= n; ++i) {
		// 	printf("%d ",disjoint[i]);
		// }
		// printf("\n");
		for (int i = 1; i <= n; ++i) {
			int p = i;
			int idx = vctr.size();
			for (;p != disjoint[p];) {
				vctr.push_back(p);
				p = disjoint[p];
			}
			for (int j = idx; j < vctr.size(); ++j) {
				disjoint[vctr[j]] = p;
			}
		}
		// for (int i = 1; i <= n; ++i) {
		// 	printf("%d ",disjoint[i]);
		// }
		// printf("\n");
		for (int i = 2; i <= n; ++i) {
			if (disjoint[1] != disjoint[i]) {
				printf("NO\n%d %d",1,i);
				return 0;
			}
		}
	}
	printf("YES");



	return 0;
}