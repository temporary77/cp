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
    int c = arr[0], cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] != c) {
            ++cnt;
            c = arr[i];
        }
    }
    printf("%d",cnt);
    return 0;
}
