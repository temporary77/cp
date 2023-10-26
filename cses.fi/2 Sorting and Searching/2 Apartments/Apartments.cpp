#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    int app[n], apart[m];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&app[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d",&apart[i]);
    }
    sort(app,app+n);
    sort(apart,apart+m);
    int nx = 0, mx = 0, cnt = 0;
    for (;nx < n && mx < m;) {
        // printf("%d %d %d %d %d\n",nx,mx,cnt,app[nx],apart[mx]);
        if (app[nx] >= apart[mx]) {
            if (app[nx]-apart[mx] <= k) {
                ++cnt;
                ++nx;
                ++mx;
            } else {
                ++mx;
            }
        } else {
            if (apart[mx]-app[nx] <= k) {
                ++cnt;
                ++nx;
                ++mx;
            } else {
                ++nx;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
