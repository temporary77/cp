#include <bits/stdc++.h>
using namespace std;
 
int n;
 
int mindist(int dist[], bool sptset[]) {
    int min = INT_MAX, mini;
    for (int i = 0; i < n; ++i) {
        // printf(">>> %d dist[i] %d min %d mini %d\n",i,dist[i],min,mini);
        if (min >= dist[i] && sptset[i] == 0) {
            min = dist[i];
            mini = i;
        }
    }
    // printf(">>>> %d %d\n",min,mini);
    return mini;
}
 
void dijkstra(vector<tuple<int,int,int>> graph[], int src) {
    //printf("-------------------------\n");
    int dist[n];
    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
    }
    //printf("\n");
    bool sptset[n] = {0};
    dist[src] = 0;
    for (int i = 1; i < n; ++i) {
        /*for (int i = 0; i < n; ++i) {
            printf("%d ",dist[i]);
        }
        printf("\n");
        for (int i = 0; i < n; ++i) {
            printf("%d ",sptset[i]);
        }
        printf("\n");*/
        int u = mindist(dist,sptset);
        //printf("u: %d\n",u);
        sptset[u] = 1;
        for (auto it = graph[u].begin(); it != graph[u].end(); ++it) {
            int loc = get<0>(*it);
            if (sptset[loc] == 0 && dist[u] != INT_MAX) {
                //printf("U V %d %d %d %d %d\n",u,v,dist[u],graph[u][v],flash[u][v]);
                int flash = get<2>(*it);
                int edge = get<1>(*it);
                int addist = 0;
                int curpos = 0;
                if ((dist[u]/flash)%2 == 1) {
                    addist -= (flash-dist[u]%flash)%flash;
                } else {
                    curpos += flash-(dist[u]%flash);
                }
                if (edge >= curpos)addist += ((edge-curpos)/flash+1)*flash;
                if (dist[u]+edge+addist < dist[loc]) {
                    dist[loc] = dist[u]+edge+addist;
                }
                //printf("TRIAL %d\n",dist[u]+graph[u][v]+addist);
            }
        }
    }
    printf("%d",dist[n-1]);
}
 
int main() {
    int e;
    scanf("%d%d",&n,&e);
    vector<tuple<int,int,int>> graph[n];
    int a, b, w, f;
    for (int i = 0; i < e; ++i) {
        scanf("%d%d%d%d",&a,&b,&w,&f);
        --a;
        --b;
        graph[a].push_back({b,w,f});
    }
    dijkstra(graph,0);
    return 0;
}