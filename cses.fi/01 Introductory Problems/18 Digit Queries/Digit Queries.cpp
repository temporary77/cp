#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    long long tracker = 1;
    scanf("%d",&q);
    long long arr[17];
    arr[0] = 0;
    for (long long i = 1; i < 17; ++i) {
        arr[i] = arr[i-1]+i*((long long)pow(10,i-1)*9);
    }
    for (int i = 0; i < q; ++i) {
        long long k, num, dgts;
        scanf("%lld",&k);
        for (int j = 0;; ++j) {
            if (arr[j] > k) {
                k -= arr[j-1];
                num = pow(10,j-1);
                dgts = j;
                break;
            }
        }
        long long jumplength = k/dgts;
        num += jumplength;
        int t;
        k -= jumplength*dgts;
        if (k == 0) {
            printf("%d\n",(num-1)%10);
            continue;
        }
        long long d = pow(10,dgts-1);
        for (int i = k; i > 0; --i) {
            t = num/d;
            num -= t*d;
            d /= 10;
        }
        printf("%d\n",t);
    }
    return 0;
}
