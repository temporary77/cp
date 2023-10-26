#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a;
    scanf("%lld%lld",&n,&a);
    if (n == 1) {
        printf("%lld",a*a+1);
    } else {
        printf("%lld",n*n+(n-1)*(n-1));
    }
    return 0;
}
