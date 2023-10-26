#include <bits/stdc++.h>
using namespace std;

const int N = 40;
const int sqrtN = sqrt(N);

int mnDiv[N + 5], pfac[4], cnt[4], nPFact, fact[20], dp[N + 5];

int nFact = 1;
int tmpFact = 1;
void genFactor(int i, int n){
    if(i == nPFact){
        fact[nFact++] = tmpFact;
        return;
    }
    genFactor(i + 1, 0);
    if(n < cnt[i]){
        tmpFact *= pfac[i];
        genFactor(i, n + 1);
        tmpFact /= pfac[i];
    }
}

void factor(int x){
    pfac[0] = -1;
    nPFact = 0;
    while(x > 1){
        if(nPFact == 0 || mnDiv[x] != pfac[nPFact - 1]){
            pfac[nPFact] = mnDiv[x];
            cnt[nPFact] = 1;
            ++nPFact;
        } else {
            ++cnt[nPFact - 1];
        }
        x /= mnDiv[x];
    }
    nFact = 0;
    tmpFact = 1;
    genFactor(0, 0);
}

int main(){

    for(int i = 2; i <= sqrtN; ++i){
        if(mnDiv[i] != 0){
            continue;
        }
        for(int j = i; j <= N; j += i){
            if(mnDiv[j] == 0){
                mnDiv[j] = i;
            }
        }
    }
    for(int i = sqrtN + 1; i <= N; ++i){
        if(mnDiv[i] == 0){
            mnDiv[i] = i;
        }
    }
    int x;
    scanf("%d", &x);
    dp[1] = 0;
    for(int i = 2; i <= x; ++i){
        factor(i);
        int mn = 1e9;
        for(int j = 0; j < nFact - 1; ++j){
            mn = min(mn, 1 + dp[i - fact[j]]);
        }
        dp[i] = mn;
    }
    cout << dp[x];

    return 0;
}
