#include <bits/stdc++.h>
using namespace std;

int arr[71];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		int ans = 1;
		int cur;
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				double d = (arr[j]-arr[i])/(double)(j-i);
				double idx = arr[i]-(d*i);
				int cur = 2;
				for (int k = j+1; k < n; ++k) {
					if (abs(arr[k]-(arr[i]+(k-i)*(d))) <= 1e-12) {
						++cur;
					}
				}
				ans = max(ans,cur);
				// if (mp[{d,idx}] >= 6)printf("[%d] %d %d %lf %lf\n",mp[{d,idx}],i,j,(double)d,(double)idx);
			}
		}
		printf("%d\n",n-ans);
	}
	return 0;
}