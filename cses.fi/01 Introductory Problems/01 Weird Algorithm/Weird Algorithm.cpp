#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    scanf("%lld",&n);
    printf("%lld ",n);
    for (;n != 1;) {
        if (n%2 == 0) {
            n /= 2;
        } else {
            n = 3*n+1;
        }
        printf("%lld ",n);
    }
    return 0;
}
