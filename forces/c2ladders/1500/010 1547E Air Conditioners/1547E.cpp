#include <bits/stdc++.h>
using namespace std;

int pos[300001];
int arr[300001];
int ans[300001];

int main() {
	int q;
	scanf("%d",&q);
	for (int qi = 0; qi < q; ++qi) {
		int n, k;
		scanf("%d%d",&n,&k);
		for (int i = 0; i < k; ++i) {
			scanf("%d",&pos[i]);
		}
		fill(arr+1,arr+n+1,0);
		for (int i = 0; i < k; ++i) {
			scanf("%d",&arr[pos[i]]);
		}
		int t = 2e9;
		for (int i = 1; i <= n; ++i) {
			++t;
			if (arr[i] != 0) {
				t = min(arr[i],t);
			}
			ans[i] = t;
		}
		t = 2e9;
		for (int i = n; i >= 1; --i) {
			++t;
			if (arr[i] != 0) {
				t = min(arr[i],t);
			}
			ans[i] = min(ans[i],t);
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}