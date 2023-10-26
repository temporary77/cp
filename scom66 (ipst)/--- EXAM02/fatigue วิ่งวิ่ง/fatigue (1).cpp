#include <vector>
#include "fatigue.h"
#include <bits/stdc++.h>
using namespace std;

int n;
long long tree[100005];
long long runleft[100005];
long long runright[100005];
long long goleft[100005];
long long goright[100005];
int leftmost[1000001];
int rightmost[1000001];
vector<tuple<int,int,long long>> vctr;
vector<int> w;
vector<int> ai;
int idxinvctr[100005];

void build() {
    for (int i = 1; i <= n; ++i) {
        idxinvctr[get<1>(vctr[i])] = i;
        for (int j = i-(i&-i)+1; j <= i; ++j) {
            tree[i] += get<2>(vctr[j]);
            runleft[i] += goleft[j];
            runright[i] += goright[j];
        }
    }
    return;
}

void update(int x, long long val, long long lval, long long rval) {
    for (int a = x; a <= n; a += a&-a) {
        tree[a] += val;
        runleft[a] += lval;
        runright[a] += rval;
    }
    return;
}

long long query(int x, int y) {
    if (x > y)return 0;
    long long sumy = 0;
    long long sumx = 0;
    --x;
    for (int a = y; a > 0; a -= a&-a) {
        sumy += tree[a];
    }
    for (int a = x; a > 0; a -= a&-a) {
        sumx += tree[a];
    }
    return sumy-sumx;
}

long long querygrouprunleft(int x, int y) {
    if (x > y)return 0;
    long long sumy = 0;
    long long sumx = 0;
    --x;
    for (int a = y; a > 0; a -= a&-a) {
        sumy += runleft[a];
    }
    for (int a = x; a > 0; a -= a&-a) {
        sumx += runleft[a];
    }
    return sumy-sumx;
}

long long querygrouprunright(int x, int y) {
    if (x > y)return 0;
    long long sumy = 0;
    long long sumx = 0;
    --x;
    // printf("%d %d QUERYING\n",x,y);
    for (int a = y; a > 0; a -= a&-a) {
        sumy += runright[a];
    }
    for (int a = x; a > 0; a -= a&-a) {
        sumx += runright[a];
    }
    // printf("%lld %lld RESULT\n",sumx,sumy);
    return sumy-sumx;
}

void initialize(int N, vector<int> A, vector<int> W){
    n = N;
    vctr.push_back({0,0,0});
    for (int i = 0; i < n; ++i) {
        vctr.push_back({A[i],i,W[i]});
    }
    sort(vctr.begin()+1,vctr.end());
    swap(w,W);
    swap(ai,A);
    vctr.push_back({0,0,0});
    int cur = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        if (get<0>(vctr[i]) > cur) {
            leftmost[get<0>(vctr[i])] = i;
            cur = get<0>(vctr[i]);
        }
    }
    cur = INT_MAX;
    for (int i = n; i >= 1; --i) {
        if (get<0>(vctr[i]) < cur) {
            rightmost[get<0>(vctr[i])] = i;
            cur = get<0>(vctr[i]);
        }
    }
    long long dist = 0;
    for (int i = n; i >= 1; --i) {
        goleft[i] = dist*w[get<1>(vctr[i])];
        dist += get<0>(vctr[i])-get<0>(vctr[i-1]);
    }
    dist = 0;
    for (int i = 1; i <= n; ++i) {
        goright[i] = dist*w[get<1>(vctr[i])];
        dist += get<0>(vctr[i+1])-get<0>(vctr[i]);
    }
    build();
    return;
}

void change_weight(int X, int V){
    update(idxinvctr[X],V-get<2>(vctr[idxinvctr[X]]),(goleft[idxinvctr[X]]*(V-w[X]))/w[X],(goright[idxinvctr[X]]*(V-w[X]))/w[X]);
    get<2>(vctr[idxinvctr[X]]) = V;
    goleft[idxinvctr[X]] *= V;
    goleft[idxinvctr[X]] /= w[X];
    goright[idxinvctr[X]] *= V;
    goright[idxinvctr[X]] /= w[X];
    w[X] = V;
    return;
}

long long point_fatigue(std::vector<int> B){
    if (B.size() == 0 || B.size() == 1)return 0;
    int lside = INT_MAX, rside = INT_MIN;
    int lguy = INT_MAX, rguy = INT_MIN;
    for (auto it : B) {
        if (ai[it] <= lside) {
            // if (ai[it] < lside) {
            //     lguy = idxinvctr[it];
            // } else {
            //     lguy = min(idxinvctr[it],lguy);
            // }
            lside = ai[it];
        }
        if (ai[it] >= rside) {
            // if (ai[it] > rside) {
            //     rguy = idxinvctr[it];
            // } else {
            //     rguy = max(idxinvctr[it],rguy);
            // }
            rside = ai[it];
        }
    }
    lguy = leftmost[lside];
    rguy = rightmost[rside];
    int l = lguy;
    int r = rguy;
    long long totalweight = query(lguy,rguy);
    // printf("TOTAL %lld\n",totalweight);
    for (;;) {
        // printf("%d %d\n",l,r);
        if (l >= r)break;
        int m = (l+r)/2;
        long long where = query(lguy,m);
        // printf("%d %lld <=\n",m,where);
        if (where >= totalweight-where) {
            r = m;
        } else {
            l = m+1;
        }
    }
    // printf("%d %d <<<< SO WE GON %d <<\n",lguy,rguy,l);
    long long totalleft = querygrouprunleft(lguy,l-1);
    long long subtractleft = query(lguy,l-1)*(get<0>(vctr[n])-get<0>(vctr[l]));
    long long totalright = querygrouprunright(l+1,rguy);
    long long subtractright = query(l+1,rguy)*(get<0>(vctr[l])-get<0>(vctr[1]));
    // printf("%lld %lld LEFT RIGHT %lld %lld\n",totalleft,subtractleft,totalright,subtractright);
    return totalleft-subtractleft+totalright-subtractright;
}
long long interval_fatigue(std::vector<std::vector<int>> In){

    return 0;
}