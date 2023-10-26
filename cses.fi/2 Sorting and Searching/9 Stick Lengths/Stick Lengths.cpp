#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int d = arr[n/2];
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += abs(arr[n/2]-arr[i]);
    }
    printf("%lld",cnt);
    return 0;
}
