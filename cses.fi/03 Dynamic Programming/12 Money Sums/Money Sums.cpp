#include <bits/stdc++.h>
using namespace std;

bool dp[100001];

int main() {
	int n;
	scanf("%d",&n);
	int x;
	dp[0] = 1;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&x);
		for (int j = 100000; j > 0; --j) {
			if (dp[j])continue;
			if (x > j)break;
			if (dp[j-x]) {
				dp[j] = 1;
				//printf("%d %d\n",j,x);
			}
		}
	}
	for (int i = 1; i <= 100000; ++i) {
		if (dp[i])++cnt;
	}
	printf("%d\n",cnt);
	for (int i = 1; i <= 100000; ++i) {
		if (dp[i])printf("%d ",i);
	}
	return 0;
}