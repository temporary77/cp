#include <bits/stdc++.h>
using namespace std;

int arr[35];
int bs1[1 << 18], bs2[1 << 18];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	int mid = n/2;
	for (int i = 0; i < 1 << mid; ++i) {
		int sum = 0;
		for (int j = 0; j < mid; ++j) {
			if (i&(1 << j)) {
				sum += arr[j];
				sum %= m;
			}
		}
		bs1[i] = sum;
	}
	for (int i = 0; i < 1 << (n-mid); ++i) {
		int sum = 0;
		for (int j = 0; j < n-mid; ++j) {
			if (i&(1 << j)) {
				sum += arr[j+mid];
				sum %= m;
			}
		}
		bs2[i] = sum;
	}
	sort(bs1,bs1+(1 << mid));
	sort(bs2,bs2+(1 << (n-mid)));
	/*for (int i = 0; i < 1 << mid; ++i) {
		printf("%d ",bs1[i]);
	}
	printf("\n");
	for (int i = 0; i < 1 << (n-mid); ++i) {
		printf("%d ",bs2[i]);
	}
	printf("\n");*/
	int max1 = 0;
	for (int i = -1; i < 1 << mid; ++i) {
		if (i == -1) {
			max1 = max(max1,bs2[(1 << (n-mid))-1]);
			continue;
		}
		int idx = lower_bound(bs2,bs2+(1 << (n-mid)),m-bs1[i])-bs2-1;
		if (idx == -1) {
			max1 = max(max1,bs1[i]);
		} else {
			//printf("%d %d\n",i,idx);
			max1 = max(max1,bs1[i]+bs2[idx]);
		}
	}
	printf("%d",max1);
	return 0;
}