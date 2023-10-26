#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int N = 5;

int arr[N + 5][N + 5], row, col;

lli recur(int r, int c, bool sp){
    if(c == col + 1){
        return 0;
    }
    lli mx = recur(r, c + 1, sp);
    if(r - 1 >= 1){
        mx = max(mx, recur(r - 1, c + 1, sp));
        if(sp){
            mx = max(mx, arr[r][c + 1] + recur(r - 1, c + 1, false));
        }
    }
    if(r + 1 <= row){
        mx = max(mx, recur(r + 1, c + 1, sp));
        if(sp){
            mx = max(mx, arr[r][c + 1] + recur(r + 1, c + 1, false));
        }
    }
    return arr[r][c] + mx;
}

int main(){

    scanf("%d%d", &row, &col);
    for(int i = 1; i <= row; ++i){
        for(int j = 1; j <= col; ++j){
            scanf("%d", &arr[i][j]);
        }
    }
    lli mx = 0;
    for(int r = 1; r <= row; ++r){
        mx = max(mx, recur(r, 1, true));
    }
    cout << mx;

    return 0;
}
