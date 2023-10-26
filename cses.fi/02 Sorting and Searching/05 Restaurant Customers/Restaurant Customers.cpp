#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&a[i],&b[i]);
    }
    sort(a,a+n);
    sort(b,b+n);
    int cnt = 0, mxcnt = 0, t = 1, ai = 0, bi = 0;
    for (; ai < n && bi < n;) {
        if (a[ai] == t) {
            for (;a[ai] == t;) {
                ++cnt;
                ++ai;
            }
        }
        if (b[bi] == t) {
            for (;b[bi] == t;) {
                --cnt;
                ++bi;
            }
        }
        mxcnt = max(cnt,mxcnt);
        t = min(a[ai],b[bi]);
    }
    printf("%d",mxcnt);
    return 0;
}
