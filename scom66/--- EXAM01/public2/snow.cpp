#include "snow.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[100001];
int n, m;

vector<int> find_pair(int N, int M, vector<int>U, vector<int> V){
    vector<int> ans;
    n = N;
    m = M;
    for(int i = 0; i < M; i++) {
        graph[U[i]].push_back((pair<int,int>){V[i],i});
        graph[V[i]].push_back((pair<int,int>){U[i],i});
    }
    int l = 0;
    int r = n-1;
    vector<bool> roadsalt(M,1);
    int mid = (l+r)/2;
    for (int i = 0; i <= mid; ++i) {
        roadsalt[i] = 0;
    }
    bool res = road_salt(roadsalt);
    if (res) {
        l = mid+1;
        r = n-1;
        for (;;) {
            
        }
    }
    for (;;) {
        if (l+1 >= r)break;
        int mid = (l+r)/2;
        printf("%d %d %d\n",l,r,mid);
        for (int i = l; i <= mid; ++i) {
            for (auto it : graph[i]) {
                roadsalt[it.second] = false;
            }
        }
        for (auto it : roadsalt) {
            if (it)printf("1");
            else printf("0");
        }
        printf("\n");
        bool res = road_salt(roadsalt);
        if (res) {
            l = mid+1;
        } else {
            r = mid;
            break;
        }
    }
    printf("<<<<<<<<<<<<<<\n");
    int cap1 = r;
    for (;;) {
        int mid = (l+r+1)/2;
        printf("%d %d %d\n",l,r,mid);
        for (int i = cap1; i > mid; --i) {
            for (auto it : graph[i]) {
                roadsalt[it.second] = true;
            }
        }
        for (auto it : roadsalt) {
            if (it)printf("1");
            else printf("0");
        }
        printf("\n");
        bool res = road_salt(roadsalt);
        if (res) {
            for (int i = cap1; i > mid; --i) {
                for (auto it : graph[i]) {
                    roadsalt[it.second] = false;
                }
            }
            l = mid;
        } else {
            r = mid-1;
        }
    }
    int a = l;
    for (auto it : roadsalt) {
        it = false;
    }
    for (auto it : graph[l]) {
        if (it.first == r) {
            roadsalt[it.second] = true;
            if (road_salt(roadsalt)) {
                vector<int> ans10 = {l,r};
                return ans10;
            }
            roadsalt[it.second] = false;
        }
    }
    for (int i = 0; i <= l; ++i) {
        for (auto it : graph[i]) {
            roadsalt[it.second] = true;
        }
    }
    int a;
    bool res = road_salt(roadsalt);
    if (res) {
        for (auto it : graph[r]) {
            roadsalt[it.second] = false;
        }
        if (road_salt(roadsalt)) {
            a = l;
        } else {
            a = r;
        }
    } else {
        for (auto it : roadsalt) {
            it = false;
        }
        for (int i = r; i <= n-1; ++i) {
            for (auto it : graph[i]) {
                roadsalt[it.second] = true;
            }
        }
        for (auto it : graph[l]) {
            roadsalt[it.second] = false;
        }
        if (road_salt(roadsalt)) {
            a = r;
        } else {
            a = l;
        }
    }
    l = 0;
    r = max(a,n-1-a);
    printf("%d <<\n",a);
    for (;;) {
        for (auto it : roadsalt) {
            it = false;
        }
        if (l >= r)break;
        int mid = (l+r)/2;        printf("> %d %d %d\n",l,r,mid);
        for (int i = 0; i < mid; ++i) {
            if (a+i <= n-1) {
                for (auto it : graph[a+i]) {
                    roadsalt[it.second] = true;                 
                }
            }
            if (a-i >= 0) {
                for (auto it : graph[a-i]) {
                    roadsalt[it.second] = true;           
                }
            }
        }
            for (auto it : roadsalt) {
            if (it)printf("1");
            else printf("0");
        }
        printf("\n");
        bool res = road_salt(roadsalt);
        if (!res) {
            l = mid+1;
        } else {
            r = mid;
        }
    }
    int b;
    if (l >= a-0) {
        b = a+l;
    } else if (l >= n-1-a) {
        b = a-l;
    } else {
        for (auto it : graph[a-l]) {
            roadsalt[it.second] = false;
        }
        if (road_salt(roadsalt)) {
            b = a+l;
        } else {
            b = a-l;
        }
    }
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}