#include <bits/stdc++.h>
using namespace std;
 
int arr[1001], brr[1001], dp[100001];
 
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&brr[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= 0; --j) {
            if(j >= arr[i])dp[j] = max(dp[j-arr[i]]+brr[i],dp[j]);
        }
        /*for (int j = 0; j <= m; ++j) {
            printf("%d ",dp[j]);
        }
        printf("\n");*/
    }
    printf("%d",dp[m]);
    return 0;
}
 
// (n,p) = max(n-1,p-i)(n-1,p);