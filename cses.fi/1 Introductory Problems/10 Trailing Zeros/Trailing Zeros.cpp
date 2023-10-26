#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, cnt = 0;
    scanf("%lld",&n);
    for (int i = 5; i <= n; i *= 5) {
        cnt += n/i;
    }
    printf("%lld",cnt);
    return 0;
}
