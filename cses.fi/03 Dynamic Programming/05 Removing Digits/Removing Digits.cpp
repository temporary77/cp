#include <bits/stdc++.h>
using namespace std;
 
int arr[1000001];
 
int main() {
    //freopen("test_input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int k;
    for (int i = 1; i <= 9; ++i)arr[i] = 1;
    for (int i = 10; i <= n; ++i) {
        arr[i] = INT_MAX;
        for (int exp = 1; i/exp > 0; exp *= 10) {
            int k = (i/exp)%10;
            arr[i] = min(arr[i],arr[i-k]);
        }
        ++arr[i];
    }
    printf("%d",arr[n]);
    return 0;
}