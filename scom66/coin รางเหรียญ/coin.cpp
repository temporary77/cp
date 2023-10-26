#include "coin.h"
#include <bits/stdc++.h>
using namespace std;

int n, L, q;
int mtl;
priority_queue<tuple<int,int,int,int>> pq;
priority_queue<pair<int,int>> rail;
int fenw[200001];
int ans[200001];
int tree[800001];
int lazy[800001];

void initialize(int N, vector<int> rail1, int L1) { 
    n = N;
    L = L1;
    for (int i = 0; i < rail1.size(); ++i) {
        rail.push({rail1[i],i});
    }
    return;
}

void update1(int x, int val) {
    ++x;
    for (int a = x; a <= n; a += a&-a) {
        fenw[a] += val;
    }
    return;
}

int query1(int x, int y) {
    int sx = 0;
    int sy = 0;
    ++y;
    for (int a = x; a > 0; a -= a&-a) {
        sx += fenw[a];
    }
    for (int a = y; a > 0; a -= a&-a) {
        sy += fenw[a];
    }
    return sy-sx;
}

void update2(int n, int a, int b, int x, int y, int val) {
    if (lazy[n] != 0) {
        tree[n] += lazy[n];
        if (a != b) {
            lazy[2*n] += lazy[n];
            lazy[2*n+1] += lazy[n];
        }
        lazy[n] = 0;
    }
    if (a > b || b < x || y < a) {
        return;
    }
    if (x <= a && b <= y) {
        tree[n] += val;
        if (a != b) {
            lazy[2*n] += val;
            lazy[2*n+1] += val;
        }
        return;
    }
    update2(2*n,a,(a+b)/2,x,y,val);
    update2(2*n+1,(a+b)/2+1,b,x,y,val);
    tree[n] = max(tree[2*n],tree[2*n+1]);
    return;
}

int query2(int n, int a, int b, int x, int y) {
    if (lazy[n] != 0) {
        tree[n] += lazy[n];
        if (a != b) {
            lazy[2*n] += lazy[n];
            lazy[2*n+1] += lazy[n];
        }
        lazy[n] = 0;
    }  
    if (a > b || b < x || y < a) {
        return 0;
    }
    if (x <= a && b <= y) {
        return tree[n];
    }
    return max(query2(2*n,a,(a+b)/2,x,y),query2(2*n+1,(a+b)/2+1,b,x,y));
}

vector<int> max_dist(vector<vector<int>> coins) {
    q = coins.size();
    for (int i = 0; i < q; ++i) {
        pq.push({coins[i][2],coins[i][1],coins[i][0],i});
    }
    mtl = n-L;
    for (int i = 0; i < q; ++i) {
        int a1, b1, c1, d1;
        tie(a1,b1,c1,d1) = pq.top();
        // printf("%d %d %d %d\n",a1,b1,c1,d1);
        for (;!rail.empty() && rail.top().first > get<0>(pq.top());) {
            update1(rail.top().second,1);
            if (L != 0)update2(1,0,n-1,rail.top().second-L+1,rail.top().second,1);
            // printf("%d v\n",rail.top().second);
            rail.pop();
            //printf("%d",crange);
        }
        int l = get<2>(pq.top());
        int r = n;
        for (;;) {
            // printf("%d %d\n",l,r);
            if (l >= r)break;
            int m = (l+r)/2;
            // printf(">> %d\n",query1(l,m));
            if (query1(get<2>(pq.top()),m) < get<1>(pq.top())+1) {
                l = m+1;
            } else {
                r = m;
            }
        }
        int hcovered = query2(1,0,n-1,get<2>(pq.top()),l);
        //printf("%d <<\n",hcovered);
        r = n;
        for (;;) {
            // printf("%d %d\n",l,r);
            if (l >= r)break;
            int m = (l+r)/2;
            // printf(">> %d\n",query1(l,m));
            if (query1(get<2>(pq.top()),m) < get<1>(pq.top())+hcovered+1) {
                l = m+1;
            } else {
                r = m;
            }
        }        
        //printf("%d <<\n",l);
        ans[get<3>(pq.top())] = l;
        pq.pop();
    }
    vector<int> ans2;
    for (int i = 0; i < q; ++i) {
        ans2.push_back(ans[i]);
    }
    return ans2;
}
