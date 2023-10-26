#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int arr[n+2][n+2];
    memset(arr,0,sizeof(arr));
    int cnt = 0;
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            scanf("%d",&arr[i][j]);
            if (arr[i][j] == 1) {
                int det = arr[i][j-1]+arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1];
                if (det == 0) {
                    ++cnt;
                }
            }
        }
    }
    printf("%d",cnt);
    
    return 0;
}