#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    long long arr[n+1] = {};
    for (int i = 0; i <= n; ++i) {
        if (i <= 6) {
            arr[i] = ceil(exp2(i-1));
        } else {
            for (int j = i-6; j < i; ++j) {
                arr[i] += arr[j];
            }
        }
    }
    printf("%lld\n",arr[n]);
    return 0;
}
