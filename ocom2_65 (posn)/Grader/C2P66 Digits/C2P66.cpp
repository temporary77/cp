#include <bits/stdc++.h>
using namespace std;

int main() {
    long long arr[17];
    arr[0] = 9;
    long long exp = 10;
    for (long long i = 1; i < 17; ++i) {
        arr[i] = arr[i-1]+(i+1)*9*exp;
        exp *= 10;
        //printf("%lld\n",arr[i]);
    }
    int n;
    scanf("%d",&n);
    long long k, cur, mod;
    for (int t = 0; t < n; ++t) {
        scanf("%lld",&k);
        //k = t;
        --k;
        if (k < 10) {
            printf("%lld\n",k);
            continue;
        }
        int i = 0;
        for (; i < 17; ++i) {
            if (k < arr[i])break;
        }
        cur = pow(10,i);
        k -= arr[--i];
        //printf(">>>> %d %d %d\n",k,i,cur);
        i += 2;
        cur += k/i;
        k -= (k/i)*i;
        //printf(">> %d %d %d\n",k,i,cur);
        if (k == 0) {
            printf("%d\n",(cur-1)%10);
        } else {
            mod = pow(10,i-k);
            printf("%d\n",(cur/mod)%10);
        }
    }

    return 0;
}
