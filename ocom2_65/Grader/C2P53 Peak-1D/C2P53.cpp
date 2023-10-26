#include <bits/stdc++.h>
using namespace std;

int arr[1000005];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	int l = 0, r = n-1, mid;
	for (;l <= r;) {
		mid = (l+r)/2;
		if ((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid])) {
			printf("%d",mid);
			return 0;
		}
		if (arr[mid-1] > arr[mid]) {
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	return 0;
}