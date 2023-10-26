#include <bits/stdc++.h>
using namespace std;

long long sum() {
    long long sum = 0, a;
    for (int i = 0; i < 10; ++i) {
        scanf("%lld",&a);
        sum += a;
    }
    return sum;
}
int main() {
    printf("%lld",sum());
    return 0;
}
