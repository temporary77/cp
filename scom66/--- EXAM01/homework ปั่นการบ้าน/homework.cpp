#include <vector>
#include "homework.h"
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[100001];
int cnt[100001];
long long dist[100001];
bool visited[100001];
bool review[100001];
int ans = 0;
vector<vector<int>> hw;
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

int homework(int N, std::vector<std::vector<int>> HW, std::vector<std::vector<int>> B) {
    n = N;
    swap(hw,HW);
    for (int i = 0; i < n; ++i) {
        for (auto it : B[i]) {
            // printf("%d %d\n",i,it);
            graph[it].push_back(i);
            // printf("%d %d <<<\n",it,i);
        }
    }
    for (int i = 0; i < n; ++i) {
        cnt[i] = hw[i][3];
    }
    for (int i = 0; i < n; ++i) {
        dist[i] = LLONG_MAX;
    }
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 0) {
            long long tme = hw[i][0]+((hw[i][2]-(hw[i][0]%hw[i][2]))%hw[i][2]);
            if (tme <= hw[i][1]) {
                pq.push({tme,i});
                dist[i] = 0;
            }
        }
    }
    for (;!pq.empty();) {
        long long tt, x;
        tie(tt,x) = pq.top();
        pq.pop();
        // printf("%lld %d\n",tt,x);
        if (visited[x])continue;
        visited[x] = 1;
        ++ans;
        for (auto it : graph[x]) {
            --cnt[it];
        }
        long long t;
        for (auto it : graph[x]) {
            if (cnt[it] > 0)continue;
            t = tt+1;
            long long tme2 = hw[it][0]+((hw[it][2]-(hw[it][0]%hw[it][2]))%hw[it][2]);
            long long tme = t+((hw[it][2]-(t%hw[it][2]))%hw[it][2]);
            // printf("%d %lld %lld <<\n",it,tme,tme2);
            if (t <= tme2 && tme2 <= hw[it][1] && tme2 >= hw[it][0]) {
                if (cnt[it] <= 0) {
                    if (dist[it] > tme2) {
                        dist[it] = tme2;
                        pq.push({tme2,it});
                    }
                }
            } else if (tme <= hw[it][1] && tme >= hw[it][0]) {
                if (cnt[it] <= 0) {
                    if (dist[it] > tme) {
                        dist[it] = tme;
                        pq.push({tme,it});
                    }
                }
            }
        }
    }
    return ans;
}