#include <cassert>
#include <cstdio>
#include <vector>
#include "trip.h"
#include "trip.cpp"
#include "tripreal.cpp"

signed main(int argc, const char **argv) {
    int N, Q, C;
    assert(scanf("%d%d%d", &N, &Q, &C) == 3);
    std::vector<int> W(N - 1);
    for(int i = 0; i < N - 1; i++) {
        assert(scanf("%d", &W[i]));
    }
    init_trip(N, Q, C, W);
    init_trip2(N, Q, C, W);
    for(int i = 0; i < Q; i++) {
        int O;
        assert(scanf("%d", &O));
        if(O == 1){
            int G;
            assert(scanf("%d", &G));
            toggle(G);
            toggle2(G);
        }else if (O == 2){
            int S, T, F;
            assert(scanf("%d%d%d", &S, &T, &F) == 3);
            printf("%d %d %d %d\n",S,T,F, trip(S, T, F));//, trip2(S, T, F), trip(S, T, F) == trip2(S, T, F) ? 0 : 999999999);
        }
    }
    return 0;
}