#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    /*long long ans = 1, mod = 1e9+7;
    for (int i = 0; i < n; ++i) {
        ans = (ans*2)%mod;
    }
    printf("%lld",ans);*/
    long long ans = 1, base = 2, mod = 1e9+7;
    for (;n >= 1;n /= 2) {
        if (n%2 == 1) {
            ans = (ans*base)%mod;
        }
        base = base*base%mod;
    }
    printf("%lld",ans);
    return 0;
}
