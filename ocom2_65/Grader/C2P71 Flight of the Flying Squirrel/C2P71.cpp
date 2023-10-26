#include <bits/stdc++.h>
using namespace std;

vector<int> graph[2001];
int weight[2001];
int dist[2001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int main() {
    int n, s, t;
    scanf("%d%d%d",&n,&s,&t);
    int k, l, w, u;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d",&k,&w,&u);
        weight[k] = w;
        for (int j = 0; j < u; ++j) {
            scanf("%d",&l);
            graph[k].push_back(l);
        }
    }
    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
    }
    pq.push({0,s});
    dist[s] = 0;
    int d, x;
    for (int i = 1; i < n; ++i) {
        d = pq.top().first;
        x = pq.top().second;
        pq.pop();
        for (auto it : graph[x]) {
            if (dist[it] > dist[x]+weight[x]-weight[it] && weight[x] > weight[it]) {
                dist[it] = dist[x]+weight[x]-weight[it];
                pq.push({dist[it],it});
            }
        }
    }
    if (dist[t] == INT_MAX) {
        printf("-1");
    } else {
        printf("%d",dist[t]);
    }
    return 0;
}
