#include <bits/stdc++.h>
using namespace std;

int recursion(int p[], int w[], int c, int pcur, int wcur, int k) {
    if (wcur > k) {
        return -1;
    }
    if (c == -1) {
        return pcur;
    }
    int maxp = max(recursion(p,w,c-1,pcur+p[c],wcur+w[c],k),recursion(p,w,c-1,pcur,wcur,k));
    return maxp;
}

int main() {
    int n, k;
    scanf("%d%d",&n,&k);
    int parr[n], warr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&parr[i],&warr[i]);
    }
    printf("%d",recursion(parr,warr,n-1,0,0,k));
    return 0;
}
