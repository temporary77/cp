#include <bits/stdc++.h>
using namespace std;

void binary(long long n) {
    if (n == 0) {
        return;
    }
    binary(n/2);
    printf("%d",n%2);
}
int main() {
    long long n;
    scanf("%lld",&n);
    if (n < 0) {
        printf("error");
        return 0;
    } else if (n == 0) {
        printf("0");
        return 0;
    }
    binary(n);
    return 0;
}
