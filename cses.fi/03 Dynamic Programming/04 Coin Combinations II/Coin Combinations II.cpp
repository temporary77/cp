#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9+7;
int arr[1000001];
 
int main() {
    //freopen("test_input.txt","r",stdin);
    int n, m;
    scanf("%d%d",&n,&m);
    int k;
    arr[0] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&k);
        for (int j = 1; j <= m; ++j) {
            if(j >= k)arr[j] += arr[j-k];
            arr[j] %= mod;
        }
    }
    /*for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }*/
    printf("%d",arr[m]);
    return 0;
}
//2 2 2 2 2
//2 2 3 3
//2 3 5
//5 5