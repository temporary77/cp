#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    long long arr[n], max1 = -1, pole1, pole2;
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&arr[i]);
        for (int j = i; j >= 0; --j) {
            if (min(arr[i],arr[j])*(i-j) > max1) {
                max1 = min(arr[i],arr[j])*(i-j);
                pole1 = j;
                pole2 = i;
            } else if (min(arr[i],arr[j])*(i-j) == max1 && j < pole1) {
                pole1 = j;
                pole2 = i;
            }
        }
    }
    printf("%lld %lld\n%lld",pole1,pole2,max1);
    return 0;
}
