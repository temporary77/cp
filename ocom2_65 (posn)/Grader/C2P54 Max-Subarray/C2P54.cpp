#include <bits/stdc++.h>
using namespace std;

int arr[20005];

long long crosssum(int l, int m, int r) {
	long long sum = 0, ls = 0, rs = 0;
	for (int i = m-1; i >= l; --i) {
		sum += arr[i];
		if (sum > ls)ls = sum;
	}
	sum = 0;
	for (int i = m+1; i <= r; ++i) {
		sum += arr[i];
		if (sum > rs)rs = sum;
	}
	return ls+rs+arr[m];
}

long long maxsum(int l, int r) {
	if (l > r)return LONG_LONG_MIN;
	if (l == r)return arr[l];
	int m = (l+r)/2;
	return max(max(maxsum(l,m-1),maxsum(m+1,r)),crosssum(l,m,r));
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	long long ans = maxsum(0,n-1);
	if (ans < 0)ans = 0;
	printf("%lld",ans);
	return 0;
}