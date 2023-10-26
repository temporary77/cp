#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        long long a, b;
        scanf("%lld%lld",&a,&b);
        printf(2*a >= b && 2*b >= a && (a+b)%3 == 0? "YES\n" : "NO\n");
    }
    return 0;
}
