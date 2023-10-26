#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p = 0, c;
    long long cnt = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&c);
        if (c < p) {
            cnt += p-c;
        } else {
            p = c;
        }
    }
    printf("%lld",cnt);
    return 0;
}
