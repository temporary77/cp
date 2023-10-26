#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    int bth[n], prc[m];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&bth[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d",&prc[i]);
    }
    sort(bth,bth+n,greater<int>());
    sort(prc,prc+m,greater<int>());
    int bi = 0, pi = 0;
    int sum = 0;
    for (;bi < n && pi < m;) {
        if (bth[bi] > prc[pi]) {
            ++bi;
        } else {
            sum += prc[pi];
            ++bi;
            ++pi;
        }
    }
    printf("%d",sum);
}