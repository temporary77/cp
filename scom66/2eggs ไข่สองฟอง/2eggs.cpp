#include "2eggs.h"
#include <bits/stdc++.h>

int height_threshold(int N, int Q) {
    int h = Q;
    for (; h < N && Q > 0;) {
        if (drop_egg(1,h)) {
            break;
        }
        --Q;
        h += Q;
    }
    int hmax = h;
    h -= Q;
    ++h;
    for (; h < hmax && h < N;) {
        if (drop_egg(2,h)) {
            break;
        }
        ++h;
    }
    return h;
}