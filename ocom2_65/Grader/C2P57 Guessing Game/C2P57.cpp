#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main() {
	int n, y, z;
	scanf("%d%d%d",&n,&y,&z);
	if (y > z)swap(y,z);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = y+1;
	for (int i = 3; i <= n; ++i) {
		dp[i] = INT_MAX;
		//printf("i >> %d\n",i);
		for (int j = 1; j <= (i-1)/2; ++j) {
			//printf("%d+%d, %d+%d\n",j,z,i-j-1,y);
			dp[i] = min(dp[i],max(y+dp[i-j-1],z+dp[j]));
		}
		dp[i] = min(dp[i],y+dp[i-1]);
	}
	/*for (int i = 1; i <= n; ++i)printf("%d ",dp[i]);
	printf("\n");*/
	printf("%d",dp[n]);
	return 0;
}