#include <bits/stdc++.h>
using namespace std;

long long unsigned fac(int n) {
    if (n == 1) {
        return 1;
    }
    return n*fac(n-1);
}
int main() {
    int n;
    scanf("%d",&n);
    printf("%llu",fac(n));
    return 0;
}
