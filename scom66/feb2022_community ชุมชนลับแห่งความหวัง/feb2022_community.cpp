#include "community.h"
#include <bits/stdc++.h>
using namespace std;

int minimum_cost(int N, vector<int> w){
    int edges[N+1];
    for (int i = 0; i < N; ++i) {
        edges[i] = (pow(2,2*(i+1))-1)*pow(2,N-i); // 2^(2*(i+1)) * 2^(N-i)
        printf("%d\n",edges[i]);
    }
    // edit this function
    return 0;
}

int main() {
    minimum_cost(3,{1,1,1});


    return 0;
}