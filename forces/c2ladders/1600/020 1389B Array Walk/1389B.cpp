#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int qs[100001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k, z;
		scanf("%d%d%d",&n,&k,&z);
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&arr[i]);
			qs[i] = qs[i-1]+arr[i];
		}
		int ans = 0;
		for (int i = 2; i <= k+1; ++i) {
			int traverses = min(z,(k-i+2)/2);
			int recoveries = min(traverses,(k-i+1)/2);
			printf("%d %d %d %d\n",i,traverses,recoveries,qs[i]+arr[i-1]*traverses+arr[i]*recoveries+qs[k+1-2*traverses]-(traverses > recoveries ? qs[i-1] : qs[i]));
			ans = max(ans,qs[i]+arr[i-1]*traverses+arr[i]*recoveries+qs[k+1-2*traverses]-(traverses > recoveries ? qs[i-1] : qs[i]));
		}
		printf("%d\n",ans);
	}
	return 0;
}