#include <bits/stdc++.h>
#include <vector>
#include "guard.h"
using namespace std;
 
const int mod = 1e9+7;
vector<int> graph[100005];
int sieve[1000005];
vector<pair<int,int>> pcnt[100005];
int size1[100005];
int primes[80005];
long long implementationcontest = 1;
int communitycentre[80005];
int bigchild[100005];
int start1[100005];
int end1[100005];
int tme[100005];
int imod[1000005];

long long powerplay(long long a, int n, int p) {
    a %= p;
    long long res = 1;
    for (;n > 0;) {
        if (n%2 == 1) {
            res *= a;
            res %= p;
        }
        a *= a;
        a %= p;
        n /= 2;
    }
    return res;
}

long long findinversemod(int x) {
    return powerplay(x,mod-2,mod);
}

int findsize(int node, int pa) {
    int sz = 0;
    int max1 = -1, bc = -1;
    for (auto it : graph[node]) {
        if (it == pa)continue;
        sz += findsize(it,node);
        if (size1[it] > max1) {
            max1 = size1[it];
            bc = it;
        }
    }
    ++sz;
    size1[node] = sz;
    bigchild[node] = bc;
    return sz;
}

int timer = 0;
void eulertour(int node, int pa) {
    // printf("%d %d\n",node,timer);
    start1[node] = timer;
    tme[timer] = node;
    ++timer;
    for (auto it : graph[node]) {
        if (it != pa) {
            eulertour(it,node);
        }
    }
    end1[node] = timer;
    return;
}

void add1(int node) {
    // printf("adding %lld\n",implementationcontest);
    for (auto it : pcnt[node]) {
        implementationcontest *= it.second+communitycentre[it.first]+1;
        implementationcontest %= mod;
        implementationcontest *= imod[communitycentre[it.first]+1];
        implementationcontest %= mod;
        communitycentre[it.first] += it.second;
    }
    // printf("added %lld\n",implementationcontest);
    return;
}

void del1(int node) {
    // printf("deleting %lld\n",implementationcontest);
    for (auto it : pcnt[node]) {
        // printf("%d %d %d\n",node,communitycentre[it.first],it.second);
        implementationcontest *= communitycentre[it.first]-it.second+1;
        implementationcontest %= mod;
        implementationcontest *= imod[communitycentre[it.first]+1];
        implementationcontest %= mod;
        communitycentre[it.first] -= it.second;
    }
    // printf("deleted %lld\n",implementationcontest);
    return;
}

void sack(vector<int> &ans, int node, int pa, bool keep) {
    //printf("%d\n",node);
    for (auto it : graph[node]) {
        if (it == pa || it == bigchild[node])continue;
        sack(ans,it,node,0);
    }
    if (bigchild[node] != -1) {
        sack(ans,bigchild[node],node,1);
    }
    // printf("%d <<\n",node);
    add1(node);
    for (auto it : graph[node]) {
        if (it == pa || it == bigchild[node])continue;
        for (int tt = start1[it]; tt < end1[it]; ++tt) {
            add1(tme[tt]);
        }
    }
    // printf("%d %d %d\n",node,arr[node],res);
    // printf("%lld\n",implementationcontest);
    ans[node] = implementationcontest;
    if (!keep) {
        for (int tt = start1[node]; tt < end1[node]; ++tt) {
            // printf("%d %d TIME\n",tt,tme[tt]);
            del1(tme[tt]);
        }
    }
    // printf("%lld\n",implementationcontest);
    return;
}
 
vector<int> guard(int n, vector<int> arr, vector<int> prr) {
    vector<int> ans(n);
    int max1 = INT_MIN;
    for (auto it : arr) {
        max1 = max(max1,it);
    }
    int iter = 1;
    int cnt = 0;
    sieve[0] = -1;
    sieve[1] = -1;
    for (long long i = 2; i <= 1000001; ++i) {
        if (sieve[i] == 0) {
            sieve[i] = iter;
            primes[iter] = i;
            //if (i >= sqrt(INT_MAX))continue;
            for (long long j = i*i; j <= 1000001; j += i) {
                sieve[j] = iter;
            }
            ++iter;
        }
    }
    for (int i = 1; i <= 1000000; ++i) {
        imod[i] = findinversemod(i);
    }
    for (int i = 0; i < n; ++i) {
        for (;arr[i] > 1;) {
            int lp = sieve[arr[i]];
            int cnt = 1;
            arr[i] /= primes[lp];
            // if (lp == 0) {
            //     lp = arr[i];
            // }
            for (;;) {
                if (sieve[arr[i]] == lp) {
                    ++cnt;
                    arr[i] /= primes[lp];
                } else {
                    break;
                }
            }
            pcnt[i].push_back({lp,cnt});
        }
    }
    for (int i = 1; i < n; ++i) {
        graph[prr[i]].push_back(i);
    }
    // for (int i = 0; i < n; ++i) {
    //     for (auto it2 : pcnt[i]) {
    //         printf("{%d,%d} ",it2);
    //     }
    //     printf("\n");
    // }
    findsize(0,-1);
    eulertour(0,-1);
    sack(ans,0,-1,1);
    // edit this
    return ans;
}
