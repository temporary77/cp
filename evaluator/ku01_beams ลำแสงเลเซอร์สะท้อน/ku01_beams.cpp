#include <bits/stdc++.h>
using namespace std;

int arr[501];
int brr[501];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d",&brr[i]);
	}
	int ai = 0;
	bool oppo = 0;
	int bi = 0;
	int cnt = 1;
	for (;;) {
		if (ai == n || bi == m)break;
		//printf("%d | %d %d and %d %d with %d\n",cnt,arr[ai],arr[ai+1],brr[bi],brr[bi+1],oppo);
		if (oppo) {
			if (arr[ai] == brr[bi]) {
				if (arr[ai+1] < brr[bi+1]) {
					++ai;
				} else {
					++bi;
				}
				++cnt;
				oppo ^= 1;
			} else if (arr[ai] < brr[bi]) {
				if (arr[ai+1] < brr[bi]) {
					++ai;
				} else if (arr[ai+1] > brr[bi+1]) {
					++bi;
					++cnt;
				} else if (arr[ai+1] < brr[bi+1]) {
					++ai;
					++cnt;
				} else if (arr[ai+1] == brr[bi+1]) {
					++ai;
					++bi;
					++cnt;
					oppo ^= 1;
				}
				oppo ^= 1;
			} else if (brr[bi] < arr[ai]) {
				if (brr[bi+1] < arr[ai]) {
					++bi;
				} else if (brr[bi+1] > arr[ai+1]) {
					++ai;
					++cnt;
				} else if (brr[bi+1] < arr[ai+1]) {
					++bi;
					++cnt;
				} else if (brr[bi+1] == arr[ai+1]) {
					++ai;
					++bi;
					++cnt;
					oppo ^= 1;
				}
				oppo ^= 1;
			}
		} else {
			if (arr[ai] == brr[bi]) {
				if (arr[ai+1] < brr[bi+1]) {
					++ai;
				} else {
					++bi;
				}
				oppo ^= 1;
			} else if (arr[ai] < brr[bi]) {
				if (arr[ai+1] > brr[bi+1]) {
					++cnt;
					++bi;
					oppo ^= 1;
				} else if (arr[ai+1] < brr[bi+1]) {
					++ai;
					oppo ^= 1;
				} else if (arr[ai+1] == brr[bi+1]) {
					++cnt;
					++ai;
					++bi;
				}
			} else if (brr[bi] < arr[ai]) {
				if (brr[bi+1] > arr[ai+1]) {
					++cnt;
					++ai;
					oppo ^= 1;
				} else if (brr[bi+1] < arr[ai+1]) {
					++bi;
					oppo ^= 1;
				} else if (brr[bi+1] == arr[ai+1]) {
					++cnt;
					++ai;
					++bi;
				}
			}	
		}
	}
	printf("%d",cnt);
	return 0;
}