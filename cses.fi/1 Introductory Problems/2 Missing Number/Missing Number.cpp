#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, a;
    scanf("%lld",&n);
    long long int sum = n*(n+1)/2;
    for (int i = 1; i < n; ++i) {
        scanf("%lld",&a);
        sum -= a;
    }
    printf("%lld",sum);
    return 0;
}
