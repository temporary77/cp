#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, t;
    scanf("%d%d",&x,&t);
    vector<int> vctr;
    int k, m, n;
    vctr.push_back(0);
    for (int i = 0; i < x; ++i) {
        scanf("%d",&k);
        vctr.push_back(k);
    }
    vctr.push_back(0);
    for (int i = 0; i < t; ++i) {
        scanf("%d",&k);
        if (k == 1) {
            scanf("%d%d",&m,&n);
            if (vctr[m] < n)++vctr[m];
        } else if (k == 2) {
            scanf("%d%d",&m,&n);
            if (vctr[m] >= n)--vctr[m];
        } else if (k == 3) {
            scanf("%d%d",&m,&n);
            for (int mm = m-1; mm <= m+1; ++mm) {
                if (mm == 0 || mm == x+1)continue;
                if (vctr[mm]-n > 0) {
                    vctr[mm] -= 3;
                } else if (vctr[mm]-n == 0) {
                    vctr[mm] -= 2;
                } else if (vctr[mm]-n == -1) {
                    vctr[mm] -= 1;
                }
                if (vctr[mm] < 0)vctr[mm] = 0;
            }
        } else if (k == 4) {
            scanf("%d",&n);
            for (int j = 1; j <= x; ++j) {
                if (vctr[j] >= n)--vctr[j];
            }
        }
        for (int j = 1; j <= x; ++j) {
            printf("%d ",vctr[j]);
        }
        printf("\n");
    }
    return 0;
}