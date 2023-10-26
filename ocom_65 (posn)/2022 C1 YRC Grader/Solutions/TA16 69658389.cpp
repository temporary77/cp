#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int N = 5000;
const int B = 4e7;
const int X = 2 * B;

int a[N + 5], b[N + 5], c[N + 5], fcd[X + 5];

int main(){

    int tr, nA, nB, nC, nD;
    scanf("%d%d%d%d%d", &tr, &nA, &nB, &nC, &nD);
    for(int i = 1; i <= nA; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= nB; ++i){
        scanf("%d", &b[i]);
    }
    for(int i = 1; i <= nC; ++i){
        scanf("%d", &c[i]);
    }
    for(int i = 1; i <= nD; ++i){
        int x;
        scanf("%d", &x);
        for(int j = 1; j <= nC; ++j){
            int sum = x + c[j];
            ++fcd[B + sum];
        }
    }
    lli cnt = 0;
    for(int i = 1; i <= nA; ++i){
        for(int j = 1; j <= nB; ++j){
            int x = tr - a[i] - b[j];
            if(-B <= x && x <= B){
                cnt += fcd[B + x];
            }
        }
    }
    cout << cnt;

    return 0;
}
