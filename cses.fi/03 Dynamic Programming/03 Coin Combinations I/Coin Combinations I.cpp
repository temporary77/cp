#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9+7;
long long dp[1000001];
 
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    dp[0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[j] <= i) {
                dp[i] += dp[i-arr[j]];
            }
        }
        dp[i] %= mod;
    }
    if (dp[m] < 0)dp[m] += mod;
    printf("%lld",dp[m]);
    return 0;
}
//3 11 3 5 7