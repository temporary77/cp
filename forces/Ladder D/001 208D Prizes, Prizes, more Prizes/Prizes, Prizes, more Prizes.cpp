#include <bits/stdc++.h>
using namespace std;

int arr[51];
int brr[5];
long long crr[5];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < 5; ++i) {
		scanf("%d",&brr[i]);
	}
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		cur += arr[i];
		for (;;) {
			int idx = upper_bound(brr,brr+5,cur)-brr-1;
			if (idx == -1)break;
			int bought = cur/brr[idx];
			crr[idx] += bought;
			cur -= bought*brr[idx];
		}
	}
	for (int i = 0; i < 5; ++i) {
		printf("%I64d ",crr[i]);
	}
	printf("\n%d",cur);
	return 0;
}