#include <bits/stdc++.h>
using namespace std;

long long walk(int n) {
    long long a = floor(pow(2,n-1));
    for (int i = 8; i-3 < n; i += 8) {
        a += pow(-1,i/8)*floor((n-(i-6)*(n-(i-3))*pow(2,n-i)));
    }
    return a;
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= 30; ++i) {
    printf("%lld\n",walk(i));
    }
    return 0;
}
