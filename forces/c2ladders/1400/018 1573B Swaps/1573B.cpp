#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			arr[(a-1)/2] = i;
		}
		int ans = n-1;
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			int b;
			scanf("%d",&b);
			b /= 2;
			if (b > cur) {
				for (int j = cur; j < b; ++j) {
					ans = min(ans,arr[j]+i);
				}
				cur = b;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}