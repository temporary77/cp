#include <bits/stdc++.h>
using namespace std;

int arr[5001];
int brr[5001];

int main() {
	int n;
	scanf("%d",&n);
	long long init = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d",&brr[i]);
		init += arr[i]*(long long)brr[i];
	}
	long long ans = init;
	for (int i = 1; i < n-1; ++i) {
		long long cur = init;
		for (int j = 1; i-j >= 0 && i+j < n; ++j) {
			cur += (arr[i-j]-arr[i+j])*(long long)(brr[i+j]-brr[i-j]);
			ans = max(ans,cur);
		}
	}
	for (int i = 0; i < n-1; ++i) {
		long long cur = init;
		for (int j = 1; i+1-j >= 0 && i+j < n; ++j) {
			cur += (arr[i+1-j]-arr[i+j])*(long long)(brr[i+j]-brr[i+1-j]);
			ans = max(ans,cur);
		}
	}
	printf("%lld\n",ans);
	return 0;
}