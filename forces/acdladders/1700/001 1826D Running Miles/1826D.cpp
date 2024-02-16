#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int maxl[100001];
int maxr[100001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		int cur = INT_MIN;
		for (int i = 0; i < n; ++i) {
			cur = max(cur,arr[i]+i);
			maxl[i] = cur;
		}
		cur = INT_MIN;
		for (int i = n-1; i >= 0; --i) {
			cur = max(cur,arr[i]-i);
			maxr[i] = cur;
		}
		int ans = INT_MIN;
		for (int i = 1; i < n-1; ++i) {
			ans = max(ans,maxl[i-1]+arr[i]+maxr[i+1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}