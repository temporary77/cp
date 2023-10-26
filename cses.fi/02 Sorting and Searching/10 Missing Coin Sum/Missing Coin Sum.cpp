#include <bits/stdc++.h>
using namespace std;

long long sum = 0;

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    for (int i = 0; i < n; ++i) {
        if (arr[i] > sum+1) {
            break;
        }
        sum += arr[i];
    }
    printf("%lld",sum+1);
    return 0;
}
