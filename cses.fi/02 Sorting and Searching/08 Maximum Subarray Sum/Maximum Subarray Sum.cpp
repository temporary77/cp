#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    long long arr[n], cur[n];
    scanf("%lld",&arr[0]);
    cur[0] = arr[0];
    long long max1 = cur[0];
    for (int i = 1; i < n; ++i) {
        scanf("%lld",&arr[i]);
        cur[i] = max(arr[i],cur[i-1]+arr[i]);
        max1 = max(max1,cur[i]);
    }
    printf("%lld",max1);
    return 0;
}
