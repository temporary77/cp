#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[200002];

int main() {
	int n, x;
	scanf("%d%d",&n,&x);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i].first);
		arr[i].second = i+1;
	}
	sort(arr,arr+n);
	int i, j;
	int kx;
	for (int k = 1; k < n-1; ++k) {
		kx = x-arr[k].first;
		i = k+1;
		j = k-1;
		for (;i < n && j >= 0;) {
			if (arr[i].first+arr[j].first > kx) {
				--j;	
			} else if (arr[i].first+arr[j].first < kx) {
				++i;
			} else {
				printf("%d %d %d",arr[i].second,arr[j].second,arr[k].second);
				return 0;
			}
		}
	}
	printf("IMPOSSIBLE");
	return 0;
}