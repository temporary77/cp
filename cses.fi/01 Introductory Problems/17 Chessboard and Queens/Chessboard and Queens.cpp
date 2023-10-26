#include <bits/stdc++.h>
using namespace std;

/*int recursion(char **arr, int d) {
    if (d == 8) {
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        if (arr[d][i] != '.') continue;
        char *sndr[8];
        for (int j = 0; j < 8; ++j) {
            sndr[j] = new char[8];
            for (int k = 0; k < 8; ++k) {
                sndr[j][k] = arr[j][k];
            }
        }
        int m = 0;
        for (int j = d; j < 8; ++j) {
            sndr[j][i] = '*';
            if (i+m <= 7) sndr[j][i+m] = '*';
            if (i-m >= 0) sndr[j][i-m] = '*';
            ++m;
        }
        cnt += recursion(sndr,d+1);
    }
    return cnt;
}


int main() {
    char *arr[8];
    for (int i = 0; i < 8; ++i) {
        arr[i] = new char[8]{};
        for (int j = 0; j < 8; ++j) {
            scanf("%c",&arr[i][j]);
        }
        scanf("%*c");
    }
    printf("%d",recursion(arr,0));
    return 0;
}*/

/*#include <bits/stdc++.h>
using namespace std;

char arr[8][8] = {'.'};
bool col[8] = {0};
bool dgn1[15] = {0};
bool dgn2[15] = {0};
int cnt = 0;

void recursion(int d) {
    if (d == 8) {
        ++cnt;
        return;
    }
    for (int i = 0; i < 8; ++i) {
        if (arr[d][i] == '.' && col[i] == 0 && dgn1[d+i] == 0 && dgn2[8+d-i] == 0) {
            arr[d][i] = '*';
            col[i] = 1;
            dgn1[d+i] = 1;
            dgn2[8+d-i] = 1;
            recursion(d+1);
            arr[d][i] = '.';
            col[i] = 0;
            dgn1[d+i] = 0;
            dgn2[8+d-i] = 0;
        }
    }
    return;
}

int main() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            scanf("%c",&arr[i][j]);
        }
        scanf("%*c");
    }
    recursion(0);
    printf("%d",cnt);
    return 0;
}*/
