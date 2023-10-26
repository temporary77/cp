#include <bits/stdc++.h>
using namespace std;


long long recursion(int d, int n, long long arr[], long long cnt, long long sum) {
    if (d == n) {
        return abs(sum-2*cnt);
    }
    long long x1 = recursion(d+1,n,arr,cnt+arr[d],sum);
    long long x2 = recursion(d+1,n,arr,cnt,sum);
    return min(x1,x2);
}

int main() {
    int n;
    scanf("%d",&n);
    long long arr[n], sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&arr[i]);
        sum += arr[i];
    }
    long long min1 = recursion(1,n,arr,arr[0],sum);
    printf("%lld",min1);
    return 0;
}
