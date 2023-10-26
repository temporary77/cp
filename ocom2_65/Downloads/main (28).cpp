#include <bits/stdc++.h>
using namespace std;

map <pair<int,int>,int> mp;

int main() {
    int n;
    scanf("%d",&n);
    vector<int> vctr;
    int k;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&k);
        vctr.push_back(k);
    }
    for (int l = 0; l < n-1; ++l) {
            mp[{l,l+1}] = 0;
    }
    for (int rd = 2; rd < n; ++rd) {
        for (int l = 0; l < n-rd; ++l) {
            int max1 = -1e9;
            for (int i = l+1; i < l+rd; ++i) {
                max1 = max(max1,mp[{l,i}]+mp[{i,l+rd}]);
            }
            mp[{l,l+rd}] = max1+vctr[l]+vctr[l+rd];
        }
    }
    printf("%d",mp[{0,n-1}]);
}