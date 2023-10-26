#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }

    return 0;
}
