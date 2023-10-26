#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 10);

int arr[N + 5][N + 5];

void recur(int r, int c, int sz, int st){
    if(sz == 1){
        arr[r][c] = st;
        return;
    }
    sz /= 2;
    recur(r, c + sz, sz, st);
    recur(r, c, sz, st + sz * sz);
    recur(r + sz, c, sz, st + 2 * sz * sz);
    recur(r + sz, c + sz, sz, st + 3 * sz * sz);
}

int main(){

    int n;
    scanf("%d", &n);
    recur(1, 1, (1 << n), 1);
    for(int i = 1; i <= (1 << n); ++i){
        for(int j = 1; j <= (1 << n); ++j){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
