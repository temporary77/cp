#include <bits/stdc++.h>
using namespace std;

int arr[10];
int brr[10];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int l, r;
		scanf("%d%d",&l,&r);
		for (int i = 0; i < 10; ++i) {
			arr[i] = l%10;
			l /= 10;
		}
		for (int i = 0; i < 10; ++i) {
			brr[i] = r%10;
			r /= 10;
		}
		long long cur = 0;
		long long ans = 0;
		for (int i = 9; i >= 0; --i) {
			cur *= 10;
			cur += brr[i]-arr[i];
			ans += cur;
		}
		printf("%lld\n",ans);
	}
	return 0;
}