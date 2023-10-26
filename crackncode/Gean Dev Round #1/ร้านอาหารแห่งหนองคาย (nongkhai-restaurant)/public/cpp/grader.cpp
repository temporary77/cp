#include <cassert>
#include <cstdio>
#include <vector>
#include "restaurant.h"
#include <bits/stdc++.h>
using namespace std;

stack<pair<int,long long>> stck1;
stack<pair<int,long long>> stck2;
pair<long long, long long> minmax1[5000001];
long long qs[5000001];
int n;

long long restaurant(int nn, std::vector<int> &a) {
    n = nn;
    // edit this
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        qs[i] = sum;
        //printf("%lld ",qs[i]);
    }
    //printf("\n");
    stck1.push({-1,0});
    for (int i = 0; i < n; ++i) {
        for (;!stck1.empty() && stck1.top().first >= abs(a[i]);) {
            long long pmin = stck1.top().second;
            stck1.pop();
            stck1.top().second = min(stck1.top().second,pmin);
        }
        minmax1[i].first = stck1.top().second;
        stck1.top().second = min(stck1.top().second,qs[i]);
        stck1.push({abs(a[i]),qs[i]});
    }
    stck2.push({-1,LLONG_MIN});
    for (int i = n-1; i >= 0; --i) {
        for (;!stck2.empty() && stck2.top().first >= abs(a[i]);) {
            long long pmax = stck2.top().second;
            stck2.pop();
            stck2.top().second = max(stck2.top().second,pmax);
        }
        stck2.top().second = max(stck2.top().second,qs[i]);
        minmax1[i].second = stck2.top().second;
        stck2.push({abs(a[i]),LLONG_MIN});
    }
    long long ans = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        //printf("%d %lld %lld %d %lld\n",i,minmax1[i],a[i],minmax1[i].second-minmax1[i].first);
        ans = max(ans,abs(a[i])*(minmax1[i].second-minmax1[i].first));
    }
    return ans;
}

// vector<pair<int,int>> vctr;

// bool comp(pair<int,int> a, pair<int,int> b) {
//     return abs(a.first) > abs(b.first);
// }

// long long restaurant(int n, std::vector<int> &vctr) {
//     long long sum = 0;
//     for (int i = 0; i < n; ++i) {
//         sum += a[i];
//         qs[i] = sum;
//     }
//     for (int i = 0; i < n; ++i) {
//         vctr.push_back({a[i],i});
//     }
//     sort(vctr.begin(),vctr.end(),comp);
//     dp[n-1] = max(0,vctr[n-1]);
//     for (int i = n-2; i >= 0; --i) {
//         if (dp[i+1] < 0) {
//             dp[i] = vctr[i];
//         } else {
//             dp[i] = dp[i+1]+vctr[i];
//         }
//     }
//     long long ans = LLONG_MIN;
//     for (auto it : minvct) {
//         ans = max(ans,(it.f)*dp[it.s]);
//     }
//     return 0LL;
// }

// // vector<int> vctr;
// // set<pair<int,int>> st;
// // long long qs[100001];

// // bool comp2(pair<int,int> a, pair<int,int> b) {
// //     if (a.second == b.second) {
// //         return 0;
// //     } else {
// //         return a.first < b.first;
// //     }
// // }

// // bool comp3(pair<int,int> a, pair<int,int> b) {
// //     if (a.second == b.second) {
// //         return 0;
// //     } else {
// //         return a.first > b.first;
// //     }
// // }

// // bool comp(pair<int,int> a, pair<int,int> b) {
// //     return abs(a.f) < abs(b.f);
// // }

// // long long restaurant(int n, vector<int> &a) {
// //     long long sum = 0;
// //     for (int i = 0; i < n; ++i) {
// //         sum += a[i];
// //         qs[i] = sum;
// //     }
// //     for (int i = 0; i < n; ++i) {
// //         vctr.push_back({a[i],i});
// //     }
// //     sort(vctr.begin(),vctr.end(),comp);
// //     long long ans = LLONG_MIN;
// //     int i = 0;
// //     for (;i < n;) {
// //         vector<int> idxes;
// //         int val = vctr[i].first;
// //         idxes.push_back(vctr[i].second);
// //         ++i;
// //         for (;;) {
// //             if (vctr[i].first == val) {
// //                 idxes.push_back(vctr[i].second);
// //                 ++i;
// //             }
// //         }
// //         for (auto it : idxes) {
// //             int r = st.upper_bound(it);
// //             int l = --st.upper_bound(it);
// //         }
// //     }
// //     return 0LL;
// // }

signed main(int argc, const char **argv) {
    int N;
    assert(scanf("%d", &N));
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        assert(scanf("%d", &A[i]));
    }
    printf("%lld", restaurant(N, A));
    return 0;
}