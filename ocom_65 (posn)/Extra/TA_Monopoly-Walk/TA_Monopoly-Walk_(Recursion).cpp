#include <bits/stdc++.h>
using namespace std;

long long cnt = 0;

void walk(int n) {
    if (n == 1 || n == 0) {
        cnt += 1;
        return;
    } else if (n == 2) {
        cnt += 2;
        return;
    } else if (n == 3) {
        cnt += 4;
        return;
    } else if (n == 4) {
        cnt += 8;
        return;
    } else if (n == 5) {
        cnt += 16;
        return;
    } else if (n == 6) {
        cnt += 32;
        return;
    } else {
        for (int i = n-6; i < n; ++i) {
            walk(i);
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= 20; ++i) {
        walk(i);
        printf("%lld\n",cnt);
        cnt = 0;
    }
    walk(n);
    printf("%lld\n",cnt);
    return 0;
}
