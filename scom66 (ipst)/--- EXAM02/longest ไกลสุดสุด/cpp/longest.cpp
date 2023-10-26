#include "longest.h"
#include <vector>

std::vector<std::pair<int,int>> longest(int N) {

    std::vector<std::pair<int,int>> ans;

    for (int i=0; i<N; ++i) ans.push_back(std::pair<int,int>(0,0));
    return ans;
}