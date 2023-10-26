#include <bits/stdc++.h>
using namespace std;

struct info {
    char name[50];
    int score;
    info(): score(0) {};

};

int main() {
    int n, k, a;
    scanf("%d%d",&n,&k);
    info stdnts[n];
    for (int i = 0; i < n; ++i) {
        int min1 = 100;
        scanf(" %[^1234567890]",stdnts[i].name);
        for (int j = 0; j < k; ++j) {
            scanf("%d",&a);
            stdnts[i].score += a;
            if (a < min1) {
                min1 = a;
            }
        }
        stdnts[i].score -= min1;
    }
    int p;
    scanf("%d",&p);
    for (int i = 0; i < n; ++i) {
        if (stdnts[i].score >= p*(k-1)/10) {
            printf("%s\n",stdnts[i].name);
        }
    }
    return 0;
}
