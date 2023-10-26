#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int N = 1000;

lli height[N + 5];

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &height[i]);
    }

    int l = 1, r = n;
    lli mx = 0;
    for(int i = 1; i < n; ++i){
        for(int j = i + 1; j <= n; ++j){
            lli mnHeight = min(height[i], height[j]);
            lli area = mnHeight * (j - i);
            if(area > mx){
                mx = area;
                l = i;
                r = j;
            }
        }
    }
    cout << l - 1 << ' ' << r - 1 << '\n' << mx;

    return 0;
}
