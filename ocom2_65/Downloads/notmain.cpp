#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    long long max1 = 0, cur = 0, cnt = 1;
    map<int,int> mp;
    for (int i = 0; i < n; ++i) {
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            printf("%d ",it->first);
        }
        printf("\n");
        if (mp[arr[i]] > 0) {
            max1 = max(max1,cur);
            cur = 0;
            mp.clear();
            cnt = 1;
            continue;
        }
        mp[arr[i]] = cnt;
        ++cur;
        ++cnt;
    }
    for (int i = 0; i < n; ++i) {
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            printf("%d ",it->first);
        }
        printf("\n");
        if (mp[arr[i]] > 0) {
            max1 = max(max1,cur);
            break;
        }
        mp[arr[i]] = cnt;
        ++cur;
        ++cnt;
    }
    max1 = max(max1,cur);
    printf("%lld",max1);
    
    return 0;
}