#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int N = 60;

lli dp[N + 5], qs[N + 5];

int main(){

    int n;
    scanf("%d", &n);
    dp[0] = 1;
    qs[0] = 1;
    for(int i = 1; i <= n; ++i){
        dp[i] = qs[i - 1] - (i - 7 < 0 ? 0 : qs[i - 7]);
        qs[i] = dp[i] + qs[i - 1];
    }
    cout << dp[n];

    return 0;
}
