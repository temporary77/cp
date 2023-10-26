#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3][4] = {
        {1,0,12,-1},
        {7,-3,2,5},
        {-5,-2,2,-9}
    };
    for (int j = 0; j < 4; ++j) {
        if (a[0][j] > a[1][j]) {
            swap(a[0][j],a[1][j]);
        }
        if (a[1][j] > a[2][j]) {
            swap(a[1][j],a[2][j]);
            if (a[0][j] > a[1][j]) {
                swap(a[0][j],a[1][j]);
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%d,",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
