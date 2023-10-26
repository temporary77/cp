#include <vector>
#include "trip.h"
#include <bits/stdc++.h>
using namespace std;

// store distances
// find forced city that is farthest
// lazy def
// find farthest city possible if max fuel (for base case when no toggled)
// fenwick count toggled cities
// qs for edges
int n, q;
long long c;
//pair<int,int> ibl[100001][18];
pair<int,int> fbl[100001][18];
long long qs[100001];
set<int> st;
int fenw[100001];
bool togd[100001];
map<pair<int,int>,int> mp;

void init_trip(int N, int Q, int C, std::vector<int> W) {
    // edit this
    n = N;
    q = Q;
    c = C;
    for (int i = 0; i < n-1; ++i) {
        // printf("%d %d",i,i+1);
        qs[i+1] = qs[i]+W[i];
        // printf(" >> %lld %d\n",qs[i+1],i+1);
    }
    // for (int i = 0; i < n-1; ++i) {
    //     ibl[i][0].second = W[i];
    // }
    // for (int i = 1; i < n; ++i) {
    //     ibl[i][0].first = W[i-1];
    // }
    // for (int k = 1; k <= floor(log2(n)); ++k) {
    //     for (int i = 0; i < n-(1 << k); ++i) {
    //         ibl[i][k].second = ibl[ibl[i][k-1].second][k-1].second;
    //     }
    // }
    // for (int k = 1; k <= floor(log2(n)); ++k) {
    //     for (int i = (1 << k); i < n; ++i) {
    //         ibl[i][k].first = ibl[ibl[i][k-1].first][k-1].first;
    //     }
    // }
    int l = 0;
    int r = 0;
    long long dist = 0;
    for (;;) {
        if (r >= n-1)break;
        dist += W[r];
        ++r;
        for (;dist > c;) {
            fbl[l][0].second = r-1;
            dist -= W[l];
            ++l;
        }
    }
    for (;;) {
        if (l > n-1)break;
        fbl[l][0].second = n-1;
        ++l;
    }
    l = n-1;
    r = n-1;
    dist = 0;
    for (;;) {
        if (l <= 0)break;
        --l;
        dist += W[l];
        for (;dist > c;) {
            fbl[r][0].first = l+1;
            --r;
            dist -= W[r];
        }
    }
    for (;;) {
        if (r < 0)break;
        fbl[r][0].first = 0;
        --r;
    }
    // for (int i = 0; i <= 13; ++i) {
    //     printf("%d ",fbl[606][i].first);
    // }
    // printf("\n");
    // for (int i = 0; i <= 13; ++i) {
    //     printf("%d ",fbl[606][i].second);
    // }
    // printf("\n");
    // printf("--- %d ---- %d -- %d -----\n",c,n,(int)floor(log2(n)));
    for (int k = 1; k <= (int)floor(log2(n)); ++k) {
        for (int i = 0; i < n; ++i) {
            fbl[i][k].second = INT_MAX;
            if (i > (n-1)-(1 << k))continue;
            if (fbl[i][k-1].second == n-1 || fbl[i][k-1].second == INT_MAX) {
                continue;
            }
            fbl[i][k].second = fbl[fbl[i][k-1].second][k-1].second;
            //printf("from %d, (%d) %d times, to %d\n",i,k,1 << k,fbl[i][k].second);
        }
    }
    for (int k = 1; k <= (int)floor(log2(n)); ++k) {
        for (int i = 0; i < n; ++i) {
            fbl[i][k].first = INT_MIN;
            if (i < (1 << k))continue;
            if (fbl[i][k-1].first == 0 || fbl[i][k-1].first == INT_MIN) {
                continue;
            }
            fbl[i][k].first = fbl[fbl[i][k-1].first][k-1].first;
        }
    }
    return;
}

bool comp(int a, pair<int,int> b) {
    return a < b.second;
} 

bool comp2(int a, pair<int,int> b) {
    return a > b.first;
}

void upd(int x, int val) {
    for (int a = x+1; a <= n; a += a&-a) {
        fenw[a] += val;
    }
    return;
}

int qry(int x) {
    int res = 0;
    for (int a = x+1; a > 0; a -= a&-a) {
        res += fenw[a];
    }
    return res;
}

int fuel(int s, int t) {
    if (mp.find({s,t}) != mp.end()) {
        return mp[{s,t}];
    }
    int si = s, ti = t;
    int res = 0;
    if (s < t) {
        int cap1 = (int)floor(log2(t-s));
        for (;;) {
            // printf("%d\n",l);
            if (s >= t) {
                break;
            }
            // for (auto it : fbl[l]) {
            //     printf("%d ",it.second);
            // }
            // printf("\n");
            int idx = upper_bound(fbl[s],fbl[s]+cap1+1,t,comp)-fbl[s]-1;
            // printf("%d %d %d %d %d\n",l,T,idx,fbl[l][idx].second,fbl[l][1].second);
            //printf("now %d %d\n",cap1,idx);
            if (idx == -1) {
                ++res;
                break;
            }
            cap1 = idx;
            // printf("real %d\n",cap1);
            res += (1 << idx);
            s = fbl[s][idx].second;
        }
    } else {
        int cap1 = (int)floor(log2(s-t));
        for (;;) {
            // printf("%d\n",l);
            if (s <= t) {
                break;
            }
            // for (auto it : fbl[l]) {
            //     // printf("%d ",it.first);
            // }
            // printf("\n");
            int idx = upper_bound(fbl[s],fbl[s]+cap1+1,t,comp2)-fbl[s]-1;
            // printf("%d %d %d %d %d %d\n",cap1,l,T,idx,fbl[l][idx].first,fbl[l][1].first);
            if (idx == -1) {
                ++res;
                break;
            }
            cap1 = idx;
            res += (1 << idx);
            s = fbl[s][idx].first;
        }
    }
    mp[{si,ti}] = res;
    return res;
}

int normaldist(int s, int t, int f) {
    int res = 0;
    if (s == t)return res;
    if (s < t) {
        int l = s;
        int r = t;
        for (;;) {
            //printf("%d %d\n",l,r);
            if (l >= r)break;
            int m = (l+r+1)/2;
            if (qs[m]-qs[s] <= (long long)f) {
                l = m;
            } else {
                r = m-1;
            }
        }
        if (l >= t)return res;
        res += fuel(l,t);  
    } else { 
        int l = t;
        int r = s;
        for (;;) {
            // printf("%d %d\n",l,r);
            if (l >= r)break;
            int m = (l+r)/2;
            // printf("%lld %lld\n",qs[S],qs[m]);
            if (qs[s]-qs[m] <= (long long)f) {
                r = m; 
            } else {
                l = m+1;
            }
        }
        // printf("%d\n",l);
        if (l <= t)return res;
        res += fuel(l,t);
    }
    return res;
}

void toggle(int G) {
    // if (togd[G]) {
    //     st.erase(G);
    // }
    auto it = st.lower_bound(G);
    auto it2 = st.upper_bound(G);
    int prev, post;
    if (it == st.begin() || st.size() == 0) {
        prev = -1;
    } else {
        prev = *--it;
    }
    if (it2 == st.end()) {
        post = -1;
    } else {
        post = *it2;
    }
    int tohere = -1, fromhere = -1, overhere = -1;
    if (prev != -1) {
        tohere = fuel(prev,G);
    }
    if (post != -1) {
        fromhere = fuel(G,post);
    }
    if (prev != -1 && post != -1) {
        overhere = fuel(prev,post);
    }
    if (!togd[G]) {
        togd[G] = 1;
        st.insert(G);
        if (prev == -1 && post == -1) {
            return;
        }
        if (prev == -1) {
            upd(G,fromhere);
            return;
        }
        if (post == -1) {
            upd(prev,tohere);
            return;
        }
        upd(prev,-1*overhere);
        upd(prev,tohere);
        upd(G,fromhere);
    } else {
        togd[G] = 0;
        st.erase(G);
        if (prev == -1 && post == -1) {
            return;
        }
        if (prev == -1) {
            upd(G,-1*fromhere);
            return;
        }
        if (post == -1) {
            upd(prev,-1*tohere);
            return;
        }
        upd(prev,overhere);
        upd(prev,-1*tohere);
        upd(G,-1*fromhere);
    }
    // edit this
    return;
}

int midfuel(int x, int y) {
    if (x <= y) {
        return qry(y-1)-qry(x-1);
    } else {
        return qry(x-1)-qry(y-1);
    }
}

int trip(int S, int T, int F) {
    int ans = 0;
    if (S < T) {
        auto it = st.upper_bound(S);
        int closest;
        if (it == st.end()) {
            closest = INT_MAX;
        } else {
            closest = *it;
        }
        //printf("%d %d %d %d\n",S,T,closest,st.size());
        if (closest > T) {
            ans = normaldist(S,T,F);
        } else {
            int farthest;
            auto it2 = --st.upper_bound(T);
            farthest = *it2;
            ans = normaldist(S,closest,F)+midfuel(closest,farthest)+1+normaldist(farthest,T,c);
        }
        // printf("%d\n",l);
    } else if (T < S) {
        auto it = st.lower_bound(S);
        int closest;
        if (it == st.begin() || st.size() == 0) {
            closest = INT_MIN;
        } else {
            closest = *--it;
        }
        if (closest < T) {
            ans = normaldist(S,T,F);
        } else {
            int farthest;
            auto it2 = st.lower_bound(T);
            farthest = *it2;
            ans = normaldist(S,closest,F)+midfuel(closest,farthest)+1+normaldist(farthest,T,c);
        }
    }
    // edit this
    return ans;
}