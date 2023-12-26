#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k, z;
		scanf("%d%d%d",&n,&k,&z);
		int sum = 0;
		int held = k-2*z;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
			if (i < held)sum += arr[i];
		}
		int cur = arr[0];
		sum -= arr[0];
		int ans = 0;
		for (int i = 1; i <= k; ++i) {
			if (i < held)sum -= arr[i];
			cur += arr[i];
			int backwards = min((k-i+1)/2,z);
			int forwards = min((k-i)/2,z);
			// printf("%d %d %d %d %d %d\n",i,cur,sum,backwards,forwards,cur+backwards*arr[i-1]+forwards*arr[i]+sum);
			ans = max(ans,cur+backwards*arr[i-1]+forwards*arr[i]+sum);
		}
		printf("%d\n",ans);
	}
	return 0;
}