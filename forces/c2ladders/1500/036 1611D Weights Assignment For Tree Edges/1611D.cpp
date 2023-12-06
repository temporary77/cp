#include <bits/stdc++.h>
using namespace std;

int brr[200001];
int drr[200001];
int ans[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&brr[i]);
		}
		fill(ans+1,ans+n+1,INT_MAX);
		bool check = true;
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			int p;
			scanf("%d",&p);
			if (!check)continue;
			if (brr[p] == p) {
				ans[p] = 0;
				drr[p] = 0;
			} else if (ans[brr[p]] == INT_MAX) {
				check = false;
			} else {
				ans[p] = cur+1-drr[brr[p]];
				drr[p] = drr[brr[p]]+ans[p];
				cur = drr[p];
			}
		}
		if (!check) {
			printf("-1\n");
		} else {
			for (int i = 1; i <= n; ++i) {
				printf("%d ",ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}