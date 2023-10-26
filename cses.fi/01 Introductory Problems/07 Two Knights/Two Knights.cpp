#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    for (long long i = 1; i <= n; ++i) {
        switch (i) {
            case 1: printf("0\n"); break;
            case 2: printf("6\n"); break;
            case 3: printf("28\n"); break;
            case 4: printf("96\n"); break;
            default:
            /*printf("%lld\n",(i*i*(i*i-1)-(48+40*(i-4)+8*(i-4)*(i-4)))/2);*/
            printf("%lld\n",i*i*(i*i-1)/2-4*(i-1)*(i-2));
        }
    }
    return 0;
}
