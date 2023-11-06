#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
	int q;
	scanf("%d",&q);
	for (int qi = 0; qi < q; ++qi) {
		int n, r;
		scanf("%d%d",&n,&r);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		n = unique(arr,arr+n)-arr;
		int cnt = 0;
		for (int i = n-1; i >= 0; --i) {
			if (arr[i]-(r*cnt) <= 0)break;
			++cnt;
		}
		printf("%d\n",cnt);
	}
	return 0;
}