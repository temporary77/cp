#include <iostream>

using namespace std;

int main()
{
    int x, y, z, n, a = 0, b = 0, c = 0, xup = 1, yup = 1;
    long long sum = 0;
    scanf("%d%d%d%d", &x, &y, &z, &n);
    int t = (n - 1) / (x * y * z) + 1, ptt[x][y][z];
    for (int i = 0; i < x * y * z; ++i){
        ptt[a][b][c] = i;
        if (xup == 1) {
            if (a != x - 1) {
                ++a;
            } else {
                xup = 0;
                if (yup == 1) {
                    if (b != y - 1) {
                        ++b;
                    } else {
                        yup = 0;
                        ++c;
                    }
                } else {
                    if (b != 0) {
                        --b;
                    } else {
                        yup = 1;
                        ++c;
                    }
                }
            }
        } else {
            if (a != 0) {
                --a;
            } else {
                xup = 1;
                if (yup == 1) {
                    if (b != y - 1) {
                        ++b;
                    } else {
                        yup = 0;
                        ++c;
                    }
                } else {
                    if (b != 0) {
                        --b;
                    } else {
                        yup = 1;
                        ++c;
                    }
                }
            }
        }
    }
    for (int p = 0; p < t; ++p) {
        for (int k = 0; k < z; ++k) {
            for (int j = 0; j < y; ++j) {
                for (int i = 0; i < x; ++i) {
                    if (ptt[i][j][k] + p * x * y * z < n) {
                        printf("%d ", ptt[i][j][k] + p * x * y * z);
                        sum += ptt[i][j][k] + p * x * y * z;
                    } else {
                        printf("v ");
                    }
                }
                printf("\n");
            }
        }
        printf("%lld\n", sum);
        sum = 0;
    }
    return 0;
}
