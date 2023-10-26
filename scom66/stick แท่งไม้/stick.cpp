#include "stick.h"
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vctr;

pair<int,vector<int>> tree[800001];

void util(int &a, int &b, int &c) {
    if (a > b) {
        swap(a,b);
    }
    if (b > c) {
        swap(b,c);
    }
    if (a > b) {
        swap(a,b);
    }
    return;
}

void build(int n, int a, int b) {
    if (a > b)return;
    if (a == b) {
        tree[n] = {-1,{vctr[a]}};
        return;
    }
    build(2*n,a,(a+b)/2);
    build(2*n+1,(a+b)/2+1,b);
    tree[n].first = max(tree[2*n].first,tree[2*n+1].first);
    if (tree[2*n].second.size()+tree[2*n+1].second.size() < 3) {
        merge(tree[2*n].second.begin(),tree[2*n].second.end(),tree[2*n+1].second.begin(),tree[2*n+1].second.end(),back_inserter(tree[n].second));
    } else {
        int ai = -1, bi = -1, ci = -1;
        int xi = tree[2*n].second.size(), yi = tree[2*n+1].second.size();
        for (int i = 0; i < tree[2*n].second.size()+tree[2*n+1].second.size(); ++i) {
            if (xi == 0) {
                --yi;
                ci = bi;
                bi = ai;
                ai = tree[2*n+1].second[yi];
            } else if (yi == 0) {
                --xi;
                ci = bi;
                bi = ai;
                ai = tree[2*n].second[xi];
            } else if (tree[2*n].second[xi-1] >= tree[2*n+1].second[yi-1]) {
                --xi;
                ci = bi;
                bi = ai;
                ai = tree[2*n].second[xi];
            } else {
                --yi;
                ci = bi;
                bi = ai;
                ai = tree[2*n+1].second[yi];                
            }
            if (i >= 2) {
                if (ai+bi > ci) {
                    tree[n].first = max(tree[n].first,ai+bi+ci);
                    tree[n].second = {ai,bi,ci};
                    break;
                }
            }
            if (i == tree[2*n].second.size()+tree[2*n+1].second.size()-1) {
                merge(tree[2*n].second.begin(),tree[2*n].second.end(),tree[2*n+1].second.begin(),tree[2*n+1].second.end(),back_inserter(tree[n].second));
            }
        }
    }
    return;
}

pair<int,vector<int>> query(int n, int a, int b, int x, int y) {
    if (a > b || b < x || y < a) {
        // printf("%d %d -1 %d %d XXXX\n",a,b,x,y);
        return {-1,{}};
    }
    if (x <= a && b <= y) {
        // printf("%d %d %d ",a,b,tree[n].first);
        // for (auto it : tree[n].second) {
        //     printf("%d ",it);
        // }
        // printf("\n");
        return tree[n];
    }
    pair<int,vector<int>> q1 = query(2*n,a,(a+b)/2,x,y);
    pair<int,vector<int>> q2 = query(2*n+1,(a+b)/2+1,b,x,y);
    pair<int,vector<int>> res;
    res.first = max(q1.first,q2.first);
    if (q1.second.size()+q2.second.size() < 3) {
        merge(q1.second.begin(),q1.second.end(),q2.second.begin(),q2.second.end(),back_inserter(res.second));
    } else {
        int ai = -1, bi = -1, ci = -1;
        int xi = q1.second.size(), yi = q2.second.size();
        for (int i = 0; i < q1.second.size()+q2.second.size(); ++i) {
            if (xi == 0) {
                --yi;
                ci = bi;
                bi = ai;
                ai = q2.second[yi];
            } else if (yi == 0) {
                --xi;
                ci = bi;
                bi = ai;
                ai = q1.second[xi];
            } else if (q1.second[xi-1] >= q2.second[yi-1]) {
                --xi;
                ci = bi;
                bi = ai;
                ai = q1.second[xi];
            } else {
                --yi;
                ci = bi;
                bi = ai;
                ai = q2.second[yi];                
            }
            if (i >= 2) {
                if (ai+bi > ci) {
                    res.first = max(res.first,ai+bi+ci);
                    res.second = {ai,bi,ci};
                    break;
                }
            }
            if (i == q1.second.size()+q2.second.size()-1) {
                merge(q1.second.begin(),q1.second.end(),q2.second.begin(),q2.second.end(),back_inserter(res.second));
            }
        }
    }
    // printf("%d %d %d ",a,b,res.first);
    // for (auto it : res.second) {
    //     printf("%d ",it);
    // }
    // printf("\n");
    return res; 
}

void init(int N, vector<int> X){
    n = N;
    swap(vctr,X);
    build(1,0,n-1);
    return;
}

int max_length(int L, int R){
    if (R-L < 2)return -1;
    pair<int,vector<int>> ans = query(1,0,n-1,L,R);
    return ans.first;
}
