#include <bits/stdc++.h>
using namespace std;

struct strct {
    int a, b;
    bool operator < (const strct &rhs) const {
        if (b != rhs.b) {
            return b < rhs.b;
        } else {
            return a < rhs.a;
        }
    }
    bool operator > (const strct &rhs) const {
        if (b != rhs.b) {
            return b > rhs.b;
        } else {
            return a > rhs.a;
        }
    }
};

int main() {
    // freopen("test_input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    strct a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&a[i].a,&a[i].b);
    }
    sort(a,a+n);
    int cnt = 0, t = a[0].b, i = 0;
    for (;;) {
        ++cnt;
        for (;i < n; ++i) {
            if(a[i].a >= t)break;
        }
        if (i == n)break;
        t = a[i].b;
    }
    printf("%d",cnt);
    return 0;
}
