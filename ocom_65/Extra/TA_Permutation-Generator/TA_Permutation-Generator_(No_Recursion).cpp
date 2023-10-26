#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long fac = 1, cnt = 0, det = 0;
    scanf("%d", &n);
    int perm[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &perm[i]);
    }
    for (int i = 2; i <= n; ++i) {
        fac *= i;
    }
    for (int i = 0;; ++i) {
        int det = i, result[n] = {}, iter[n] = {}, valid = 1;
        for (int j = 0; j < n; ++j) {
            result[j] = det % n;
            det /= n;
        }
        for (int j = 0; j < n; ++j) {
            if (iter[result[j]] > 0) {
                valid = 0;
                break;
            } else {
                iter[result[j]] += 1;
            }
        }
        if (valid == 1) {
            for (int j = 1; j <= n; ++j) {
                printf("%d ", perm[result[n - j]]);
            }
            ++cnt;
            printf("\n");
        }
        if (cnt >= fac) {
            break;
        }
    }
    printf("%lld", fac);
    return 0;
}
