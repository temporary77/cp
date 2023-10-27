#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9+7;
long long dp[1000005];
 
int main() {
    int n;
    scanf("%d",&n);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    long long cur = 32;
    for (int i = 6; i <= n; ++i) {
        dp[i] = cur;
        cur += dp[i]-dp[i-6];
        cur %= mod;
        if (cur < 0)cur += mod;
    }
    printf("%lld",dp[n]);
    return 0;
}