#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    scanf("%lld",&n);
    switch (n%4) {
    case 1: printf("NO"); break;
    case 2: printf("NO"); break;
    case 3:
        printf("YES\n%lld\n1 2 ",(n+1)/2);
        for (int i = 4; i < (n+13)/4; ++i) {
            printf("%d ",i);
        }
        for (int i = (3*n+7)/4; i <= n; ++i) {
            printf("%d ",i);
        }
        printf("\n%lld\n3 ",(n-1)/2);
        for (int i = (n+13)/4; i <= (3*n+3)/4; ++i) {
            printf("%d ",i);
        }
        break;
    case 0:
        printf("YES\n%lld\n",n/2);
        for (int i = 1; i <= n/4; ++i) {
            printf("%d ",i);
        }
        for (int i = 3*n/4+1; i <= n; ++i) {
            printf("%d ",i);
        }
        printf("\n%lld\n",n/2);
        for (int i = n/4+1; i <= 3*n/4; ++i) {
            printf("%d ",i);
        }
        break;
    }
    return 0;
}
