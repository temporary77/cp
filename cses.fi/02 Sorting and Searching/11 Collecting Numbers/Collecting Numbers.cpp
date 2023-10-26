#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int arr[n], k, cnt = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&k);
        arr[k-1] = i;
    }
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i-1]) {
            ++cnt;
        }
    }
    printf("%d",cnt);
    return 0;
}
