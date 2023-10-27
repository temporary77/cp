#include <bits/stdc++.h>
using namespace std;
 
long long dp[1000001];
 
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    dp[0] = 0;
    for (int i = 1; i <= m; ++i) {
        dp[i] = LLONG_MAX;
        for (int j = 0; j < n; ++j) {
            if (arr[j] <= i) {
                dp[i] = min(dp[i],dp[i-arr[j]]);
            }
        }
        if (dp[i] != LLONG_MAX)++dp[i];
    }
    //for (int i = 0; i <= m; ++i)printf("%d ",dp[i]);
    if (dp[m] == LLONG_MAX)dp[m] = -1;
    printf("%lld",dp[m]);
    return 0;
}
//3 11 3 5 7