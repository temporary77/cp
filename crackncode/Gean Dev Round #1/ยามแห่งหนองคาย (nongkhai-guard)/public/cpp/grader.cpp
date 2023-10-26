#include <cassert>
#include <cstdio>
#include <vector>
#include "guard.h"
#include <bits/stdc++.h>
#include "guard.cpp"
using namespace std;

signed main(int argc, const char **argv) {
    int N;
    assert(scanf("%d", &N));
    vector<int> A(N), P(N);
    for(int i = 0; i < N; i++) {
        assert(scanf("%d", &A[i]));
    }
    P[0] = -1;
    for(int i = 1; i < N; i++) {
        assert(scanf("%d", &P[i]));
    }
    vector<int> Ans = guard(N, A, P);
    for(int i = 0; i < N; i++) {
        printf("%d ", Ans[i]);
    }
    return 0;
}