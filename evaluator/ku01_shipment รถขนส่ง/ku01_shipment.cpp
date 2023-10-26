#include <bits/stdc++.h>
using namespace std;

int arr[301], brr[301], crr[301], drr[301];

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d",&brr[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d",&crr[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d",&drr[i]);
	}
	sort(arr,arr+n);
	sort(brr,brr+n);
	sort(crr,crr+n);
	sort(drr,drr+n);
	int ans;
	int realans = INT_MAX;
	for (int i = max(0,k-n); i <= min(k,n); ++i) {
		ans = INT_MIN;
		for (int j = 0; j < i; ++j) {
			//printf("%d %d %d %d\n",i,j,arr[j],crr[i-1-j]);
			ans = max(ans,arr[j]+crr[i-1-j]);
		}
		for (int j = 0; j < k-i; ++j) {
			ans = max(ans,brr[j]+drr[(k-i)-1-j]);
		}
		//printf("%d %d \n",ans,i);
		realans = min(realans,ans);
	}
	printf("%d",realans);
	return 0;
}