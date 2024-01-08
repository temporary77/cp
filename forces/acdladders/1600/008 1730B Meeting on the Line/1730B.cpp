#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<int,int> arr[200001];
pair<int,int> brr[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i].f);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i].s);
		}
		if (n == 1) {
			printf("%d\n",arr[0].f);
			continue;
		}
		sort(arr,arr+n);
		int max1 = 0;
		for (int i = 0; i < n; ++i) {
			max1 = max(max1,arr[i].s);
			brr[i].f = max1;
			if (i == n-1)break;
			max1 += arr[i+1].f-arr[i].f;
		}
		max1 = 0;
		for (int i = n-1; i > 0; --i) {
			max1 = max(max1,arr[i].s);
			brr[i].s = max1;
			if (i == 0)break;
			max1 += arr[i].f-arr[i-1].f;
		}
		double cur = 2e9;
		double ans = -1;
		for (int i = 0; i < n-1; ++i) {
			// printf("%d %d %d %d\n",arr[i].f,arr[i+1].f,brr[i].f,brr[i+1].s);
			int d = arr[i+1].f-arr[i].f;
			int free = brr[i+1].s-brr[i].f;
			if (free < -d) {
				free = -d;
			} else if (free > d) {
				free = d;
			}
			double pos;
			if (free >= 0) {
				pos = arr[i].f+free+(d-free)/(double)2;
			} else {
				pos = arr[i+1].f+free-(d+free)/(double)2;
			}
			double cal = max(brr[i].f+pos-arr[i].f,brr[i+1].s+arr[i+1].f-pos);
			// printf("%g %g?\n",pos,cal);
			if (cal < cur) {
				cur = cal;
				ans = pos;
			}
		}
		printf("%.20g\n",ans);
	}
	return 0;
}