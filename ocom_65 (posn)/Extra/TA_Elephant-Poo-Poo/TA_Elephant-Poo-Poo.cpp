#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 0, d, trgt;
    scanf("%d",&n);
    bool arr[n] = {};
    for (int i = 4; i < n; i += 2) {
        arr[i] = 1;
    }
    for (int i = 1; i < n; i *= 2) {
        trgt = i;
    }
    while (n > 1) {
        d = 1;
        int exp2 = 0, exp3 = 0;
        for (int i = 2; i < n; i *= 2) {
            if (n%i == 0) {
                exp2++;
                d = i;
            } else {
                for (int j = 3; d*j < n; ++j) {
                    if (arr[j] == 0) {
                        for (int k = 2*j; k < n; k += j) {
                            arr[k] = 1;
                        }
                        for (int k = j; d*k < n; k *= j) {
                            if (n%k == 0) {
                                exp3++;
                                d *= j;
                                if (exp2 == exp3) {
                                    break;
                                }
                            } else {
                                break;
                            }
                        }
                    }

                }

                break;
            }
        }
        if (d > 1) {
            n -= d;
            cnt++;
        } else {
            bool det = 0;
            for (int i = 3; i <= n/2; ++i) {
                for (int j = i; j <= n/2; j *= i) {
                    if (n%j == 0) {
                        if (n-j < trgt) {
                            break;
                        }
                        if (n%(j*i) != 0 || j*i > n/2) {
                            det = 1;
                            n -= j;
                            cnt++;
                        }
                        break;
                    }
                }
                if (det == 1) {
                    break;
                }
            }
            if (det == 0) {
                --n;
                cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
