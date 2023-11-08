#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int max1 = INT_MIN, min1 = INT_MAX;
	int maxidx, minidx;
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		if (k > max1) {
			max1 = k;
			maxidx = i;
		}
		if (k <= min1) {
			min1 = k;
			minidx = i;
		}
	}
	int ans = maxidx+(n-minidx-1);
	if (maxidx > minidx)--ans;
	printf("%d",ans);
	return 0;
}