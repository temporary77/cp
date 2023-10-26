#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    scanf("%d%d",&n,&x);
    int arr[n];
    bool taken[n] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n,greater<int>());
    int ax = 0, bx = n-1, ans = 0;
    for (;ax <= bx;) {
        if (x >= arr[bx]+arr[ax]) {
            --bx;
        }
        ++ax;
        ++ans;
    }
    printf("%d",ans);
    return 0;
}
