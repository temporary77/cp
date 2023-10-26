#include <vector>
#include "penguin.h"

void penguin(int N) {
    if (N == 2) {
        play({1,2});
    }
    for (int i = 2; i <= N-1; ++i) {
        play({i});
    }
    for (int i = N-1; i >= 2; --i) {
        play({i});
    }        
    // edit this
    return;
}
