#include <bits/stdc++.h>
using namespace std;

int cnt[11];

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	int a;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&a);
		if (a%10) {
			++cnt[10-a%10];
		}
		ans += a/10;
	}
	for (int i = 1; i <= 9; ++i) {
		ans += min(cnt[i],k/i);
		k -= cnt[i]*i;
		if (k <= 0)break;
	}
	ans = min(10*n,ans+max(0,k)/10);
	printf("%d",ans);
	return 0;
}