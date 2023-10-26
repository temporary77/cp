#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    int arr[n+1] = {1};
    for (int i = 1; i <= n; ++i) {
        arr[i] = arr[i-1]*2;
    }
    unordered_map<int,int> mp;
    int d, a, b;
    for (int i = 0; i < m; ++i) {
        if (n == 0)printf("0\n");
        scanf("%d%d%d",&d,&a,&b);
        if (d == 0) {
            if (mp[a] == 0 && mp[b] == 0) {
                --n;
            } else if (mp[a] != 0 && mp[b] == 0) {
                mp[b] = -1*mp[a];
            } else if (mp[a] == 0 && mp[b] != 0) {
                mp[a] = -1*mp[b];
            } else if (mp[a] == mp[b]) {
                n = 0;
            }
        }
    }
    return 0;
}
