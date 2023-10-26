#include "rescue.h"
#include <bits/stdc++.h>
using namespace std;

int n, q;
int fenw[2005][2005];
int mx = 2002, my = 2002;
vector<int> X1, Y1;

void update(int x, int y, int val) {
    // printf("upd %d %d\n",x,val);
    for (int a = x; a <= mx; a += a&-a) {
        for (int b = y; b <= my; b += b&-b) {
            fenw[a][b] += val;
        }
    }
    return;
}

int query(int x1, int y1, int x2, int y2) {
    //printf("qry %d %d %d %d\n",x1,y1,x2,y2);
    int res4 = 0;
    int res3 = 0;
    int res2 = 0;
    int res1 = 0;
    --x1;
    --y1;
    for (int a = x2; a > 0; a -= a&-a) {
        for (int b = y2; b > 0; b -= b&-b) {
            res4 += fenw[a][b];
        }    }
    for (int a = x2; a > 0; a -= a&-a) {
        for (int b = y1; b > 0; b -= b&-b) {
            res3 += fenw[a][b];
        }
    }
    for (int a = x1; a > 0; a -= a&-a) {
        for (int b = y2; b > 0; b -= b&-b) {
            res2 += fenw[a][b];
        }
    }
    for (int a = x1; a > 0; a -= a&-a) {
        for (int b = y1; b > 0; b -= b&-b) {
            res1 += fenw[a][b];
        }
    }
    //if (res4-res3-res2+res1 < 0)printf("%d %d %d %d %dthe fuck\n",res4,res3,res2,res1,res4-res3-res2+res1);
    return res4-res3-res2+res1;
}

void init_rescue(int N, int Q, vector<int> X, vector<int> Y)
{   
    n = N;
    q = Q;
    for (int i = 0; i < n; ++i) {
        ++X[i];
        ++Y[i];
    }
    // printf("%d %d\n",mx,my);
    for (int i = 0; i < n; ++i) {
        // printf("%d <<<\n",X[i]);
        update(X[i],Y[i],1);
    }
    swap(X,X1);
    swap(Y,Y1);
    return;
}

int answer_query(int A, int B, int C, int D)
{
    ++A;
    ++B;
    ++C;
    ++D;
    int ans = query(A,B,C,D);
    if (ans == 0) {
        int nearest = INT_MAX;
        int l = C+1;
        int r = mx;
        for (;;) {
            // printf("%d %d\n",l,r);
            if (l >= r)break;
            int m = (l+r)/2;
            if (query(C+1,B,m,D) > 0) {
                r = m;
            } else {
                l = m+1;
            }
        }
        // printf("%d < %d\n",l,l-C);
        if (query(C+1,B,l,D) > 0)nearest = min(nearest,l-C);
        l = 1;
        r = A-1;
        for (;;) {
            if (l >= r)break;
            int m = (l+r+1)/2;
            if (query(m,B,A-1,D) > 0) {
                l = m;
            } else {
                r = m-1;
            }
        }
        // printf("%d <<<<< %d\n",l,A-l);
        if (query(l,B,A-1,D) > 0)nearest = min(nearest,A-l);
        l = D+1;
        r = my;
        for (;;) {
            // printf("%d %d\n",l,r);
            if (l >= r)break;
            int m = (l+r)/2;
            if (query(A,D+1,C,m) > 0) {
                r = m;
            } else {
                l = m+1;
            }
        }
        // printf("%d < %d\n",l,l-C);
        if (query(A,D+1,C,l) > 0)nearest = min(nearest,l-D);
        l = 1;
        r = B-1;
        for (;;) {
            if (l >= r)break;
            int m = (l+r+1)/2;
            if (query(A,m,C,B-1) > 0) {
                l = m;
            } else {
                r = m-1;
            }
        }
        // printf("%d <<<<< %d\n",l,A-l);
        if (query(A,l,C,B-1) > 0)nearest = min(nearest,B-l);
        // printf("? %d\n",nearest);
        // printf("? %d\n",nearest);
        if (nearest == INT_MAX) {
            ans = 0;
        } else {
            ans = nearest;
        }
    } else {
        ans *= -1;
    }
    return ans;
}

void cancel_request(int R)
{
    int nx = X1[R];
    int ny = Y1[R];
    // printf("%d <<<\n",nx);
    update(nx,ny,-1);
}
