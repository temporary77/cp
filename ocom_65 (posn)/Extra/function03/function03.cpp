#include <bits/stdc++.h>
using namespace std;

long long f(int x) {
    return x*x*x+abs(x);
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%lld",f(n));
    return 0;
}
