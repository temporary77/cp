#include <bits/stdc++.h>
using namespace std;

const int p = 2e7;
const int maxp = p*2;
int ab[maxp+5];

int main() {
    int nA, nB, nC, nD, S;
    long long ans = 0;
    scanf("%d%d%d%d%d",&S,&nA,&nB,&nC,&nD);
    int a[nA], b[nB], c[nC], d[nD];
    for (int i = 0; i < nA; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < nB; ++i) {
        scanf("%d",&b[i]);
    }
    for (int i = 0; i < nC; ++i) {
        scanf("%d",&c[i]);
    }
    for (int i = 0; i < nD; ++i) {
        scanf("%d",&d[i]);
    }
    for (int i = 0; i < nA; ++i) {
        for (int j = 0; j < nB; ++j) {
            ab[a[i]+b[j]+p]++;
        }
    }
    for (int i = 0; i < nC; ++i) {
        for (int j = 0; j < nD; ++j) {
            int s = S-c[i]-d[j];
            if (-p <= s && s <= p) {
                ans += ab[s+p];
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
