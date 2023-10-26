#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int nxt[N + 5], prv[N + 5], nxtS[N + 5], prvS[N + 5];

int main(){

    int n;
    scanf("%d", &n);
    int fst, lst;
    for(int i = 1; i <= n; ++i){
        nxtS[i] = i + 1;
        prvS[i] = i - 1;
        int x;
        scanf("%d", &x);
        if(i == 1){
            fst = x;
            lst = x;
            continue;
        }
        nxt[lst] = x;
        prv[x] = lst;
        lst = x;
    }
    nxt[lst] = fst;
    prv[fst] = lst;


    int md = (n + 1) / 2;
    for(int i = 1; i <= n / 2; ++i){
        int cur = md;
        int ano = nxt[md];
        if(ano > md){
            md = prvS[md];
        } else {
            md = nxtS[md];
        }
        nxt[prv[cur]] = nxt[ano];
        prv[nxt[ano]] = prv[cur];
        nxtS[prvS[cur]] = nxtS[cur];
        prvS[nxtS[cur]] = prvS[cur];
        nxtS[prvS[ano]] = nxtS[ano];
        prvS[nxtS[ano]] = prvS[ano];
    }
    cout << md;

    return 0;
}
