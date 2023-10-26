#include "triplets.h"
#include <bits/stdc++.h>
using namespace std;

const int mod = 9377;

// int power(int a, int n, int p) {
//     int res = 1;
//     a %= p;
//     for (;n > 0;) {
//         if (n&1) {
//             res *= a;
//             res %= p;
//         }
//         n /= 2;
//         a *= a;
//         a %= p;
//     }
//     return res;
// }

// int findinverse(int x, int p) {
//     return power(x,p-2,p);
// }

int n;
vector<int> graph[100001];
vector<int> color;
// int inversesix = findinverse(6,mod);

// unordered_map<int,int> mp;

int nchoose3(int x) {
    if (x < 3)return 0;
    int res = 1;
    res *= (x-2);
    res %= mod;
    res *= (x-1);
    res %= mod;
    res *= x;
    res %= mod;
    return res;
}

// long long cycles = 0;
// void dfs(int node, int cnt, int pa) {
//     if (cnt == 0) {
//         if (node == pa)++cycles;
//         return;
//     }
//     for (auto it : graph[node]) {
//         dfs(it,cnt-1,pa);
//     }
//     return;
// }

long long colorcycles = 0;

int stage[100001];
bool visited[100001];

void dfs2(int node, int cnt, int c) {
    stage[node] = cnt;
    // printf("%d %d %d\n",node,cnt,c);
    visited[node] = 1;
    for (auto it : graph[node]) {
        if (color[node] == color[it] && cnt+1-stage[it] >= 3 && visited[it]) {
            // printf("%d %d\n",node,it);
            ++colorcycles;
        }
        if (visited[it])continue;
        dfs2(it,cnt+1,c);
    }
    return;    
}

int count_triplets(int N, std::vector<int> U, std::vector<int> V, std::vector<int> C){
    n = N;
    swap(color,C);
    for (int i = 0; i < n; ++i) {
        graph[U[i]].push_back(V[i]);
    }
    long long total = nchoose3(n);
    // for (auto it : color) {
    //     ++mp[it];
    // }
    // long long samec = 0;
    // for (auto it : mp) {
    //     samec += nchoose3(it.second);
    // }
    // for (int i = 0; i < n; ++i) {
    //     dfs(i,3,i);
    // }
    dfs2(0,0,color[0]);
    // printf("%lld %lld\n",total,colorcycles);
    return total-colorcycles*6;
}
