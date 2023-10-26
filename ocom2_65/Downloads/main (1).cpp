#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    int max1 = 0, warp = 0;
    map<int,int> mp;
    for (int i = 0; i < n; ++i) {
        /*for (auto it = mp.begin(); it != mp.end(); ++it) {
            printf("%d ",it->first);
        }
        printf("\n");
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            printf("%d ",it->second);
        }
        printf("\n----- %d %d %d\n",max1,warp,i);*/
        if (mp[arr[i]] > warp) {\
            max1 = max(max1,i-warp);
            warp = mp[arr[i]];
        }
        mp[arr[i]] = i+1;
    }
    max1 = max(max1,n-warp);
    printf("%d",max1);
    
    return 0;
}