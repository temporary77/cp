#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    scanf("%lld%lld%lld",&a,&b,&c);
    if (a < b) {
        swap(a,b);
    }
    if (b < c) {
        swap(b,c);
        if (a < b) {
            swap(a,b);
        }
    }
    printf("%lld %lld %lld",a,b,c);
    return 0;
}