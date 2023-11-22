#include <bits/stdc++.h>
using namespace std;

int arr[200001];
int wrr[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		for (int i = 0; i < k; ++i) {
			scanf("%d",&wrr[i]);
		}
		sort(arr,arr+n,greater<int>());
		sort(wrr,wrr+k);
		long long ans = 0;
		int wi = 0;
		for (int i = 0; i < k; ++i) {
			ans += arr[i];
			if (wrr[wi] == 1) {
				ans += arr[i];
				++wi;
			}
		}
		int idx = k-1;
		for (; wi < k; ++wi) {
			idx += wrr[wi]-1;
			ans += arr[idx];
		}
		printf("%lld\n",ans);
	}
	return 0;
}