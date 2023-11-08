#include <bits/stdc++.h>
using namespace std;

int arr[200005];
int cnt[200005];

int main() {
	int n;
	scanf("%d",&n);
	int max1 = -1;
	int val = -1;
	int idx;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		++cnt[arr[i]];
		if (cnt[arr[i]] > max1) {
			max1 = cnt[arr[i]];
			if (val != arr[i]) {
				val = arr[i];
				idx = i;
			}
		}
	}
	printf("%d\n",n-max1);
	for (int i = 1; i < n; ++i) {
		if (arr[i-1] == val) {
			if (arr[i] != val) {
				if (arr[i] > val) {
					printf("2 %d %d\n",i+1,i);
				} else {
					printf("1 %d %d\n",i+1,i);
				}
				arr[i] = val;
			}
		}
	}
	for (int i = idx-1; i >= 0; --i) {
		if (arr[i+1] == val && arr[i] != val) {
			if (arr[i] > val) {
				printf("2 %d %d\n",i+1,i+2);
			} else {
				printf("1 %d %d\n",i+1,i+2);
			}
			arr[i] = val;
		}
	}
	return 0;
}