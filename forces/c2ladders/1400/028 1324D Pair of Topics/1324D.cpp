#include <bits/stdc++.h>
using namespace std;

int arr[200001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < n; ++i) {
		int b;
		scanf("%d",&b);
		arr[i] -= b;
	}
	sort(arr,arr+n);
	int idx = n-1;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (;idx >= i && arr[i] > -1*arr[idx];) {
			--idx;
		}
		if (idx < i)idx = i;
		ans += n-idx-1;
	}
	printf("%lld\n",ans);
	return 0;
}