#include <bits/stdc++.h>
using namespace std;

int arr[100002];

int main() {
	int n;
	scanf("%d",&n);
	arr[0] = INT_MIN;
	arr[n+1] = INT_MAX;
	int r = -1;
	int l = -1;
	int curmax = INT_MIN;
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
		if (curmax > arr[i]) {
			r = i;
		}
		curmax = max(curmax,arr[i]);
	}
	if (r == -1) {
		printf("YES");
		return 0;
	}
	for (int i = 1; i < r; ++i) {
		if (arr[i] > arr[r]) {
			l = i;
			break;
		}
	}
	swap(arr[l],arr[r]);
	for (int i = 1; i <= n; ++i) {
		if (arr[i-1] > arr[i]) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}