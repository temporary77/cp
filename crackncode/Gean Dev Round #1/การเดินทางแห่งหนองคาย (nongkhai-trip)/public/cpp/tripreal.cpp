#include <bits/stdc++.h>
#include "trip.h"
using namespace std;
struct segment_tree{
    long long sum[100001], prefix_sum[100001], c, n;
    pair<int, int> stations[400004];
    vector<long long> next_station[100001];
    bool station[100001];
    long long sum_range(int l, int r){
        return prefix_sum[r]-prefix_sum[l];
    }
    void update_sum(int x, int y){
        while(x <= n){
            sum[x] += y;
            x += x&(-x);
        }
    }
    long long get_sum(int z){
        if(!z)return 0LL;
        return sum[z] + get_sum(z - (z&(-z)));
    }
    int first_station(int N, int x, int y, int s, int t){
        if(x > t || y < s)return -1;
        if(x <= s && y >= t){
            return stations[N].first;
        }
        int X = first_station(2*N, x, y, s, (s+t)/2);
        int Y = first_station(2*N+1, x, y, (s+t)/2+1, t);
        if(X != -1)return X;
        return Y;
    }
    int last_station(int N, int x, int y, int s, int t){
        if(x > t || y < s)return -1;
        if(x <= s && y >= t){
            return stations[N].second;
        }
        int X = last_station(2*N, x, y, s, (s+t)/2);
        int Y = last_station(2*N+1, x, y, (s+t)/2+1, t);
        if(Y != -1)return Y;
        return X;
    }
    void init(int N, long long C, vector<int> W){
        c = C;
        n = N;
        for(int i = 0; i < 4*N; i++){
            stations[i] = make_pair(-1LL, -1LL);
        }
        sum[N] = 0LL;
        for(int i = 0; i < N; i++){
            sum[i] = 0LL;
            station[i] = false;
            if(i)prefix_sum[i] = W[i-1];
            if(i)prefix_sum[i]+=prefix_sum[i-1];
            next_station[i].clear();
        }
        for(int i = N-2; i >= 0; i--){
            int l = i+1, r = N-1;
            while(l < r){
                int m = (l+r+1)/2;
                if(sum_range(i, m) > C)r = (l+r)/2;
                else l = m;
            }
            next_station[i].push_back(l);
            while(next_station[r].size() >= next_station[i].size()){
                next_station[i].push_back(next_station[r][next_station[i].size()-1]);
                r = next_station[i][next_station[i].size()-1];
            }
        }
    }
    int far_station(int x, long long y){
        int l = x, r = n-1;
        while(l < r){
            int m = (l+r+1)/2;
            if(sum_range(x, m) > y)r = (l+r)/2;
            else l = m;
        }
        return r;
    }
    int close_station(int x, long long y){
        int l = 0, r = x;
        while(l < r){
            int m = (l+r)/2;
            if(sum_range(m, x) > y)l = (l+r+1)/2;
            else r = m;
        }
        return r;
    }
    int get_distance_init(int x, int y, int index){
        if(x == n-1)return 0;
        if(index >= next_station[x].size())index = next_station[x].size()-1;
        if(next_station[x][0] >= y)return 0;
        if(!index)index = next_station[x].size()-1;
        while(next_station[x][index] >= y)index--;
        return (1<<index)+get_distance_init(next_station[x][index], y, index);
    }
    void update_station(int N, int x, int y, int z){
        if(x > z || y < z)return;
        if(x == z && y == z){
            if(station[z]){
                station[z] = false;
                stations[N] = make_pair(-1, -1);
                int X = -1;
                if(z < N-1)X = first_station(1, z+1, n-1, 0, n-1);
                int Y = -1;
                if(z)Y = last_station(1, 0, z-1, 0, n-1);
                if(X != -1){
                    update_sum(X+1, -get_distance_init(z, X, 0)-1);
                    if(Y != -1){
                        update_sum(X+1, get_distance_init(Y, X, 0)+1);
                    }
                    else update_sum(X+1, get_distance_init(0, X, 0)+1);
                }
                if(Y != -1){
                    update_sum(z+1, -get_distance_init(Y, z, 0)-1);
                }
                else update_sum(z+1, -get_distance_init(0, z, 0)-1);
                return;
            }
            station[z] = true;
            stations[N] = make_pair(z, z);
            int X = -1;
            if(z < N-1)X = first_station(1, z+1, n-1, 0, n-1);
            int Y = -1;
            if(z)Y = last_station(1, 0, z-1, 0, n-1);
            if(X != -1){
                update_sum(X+1, get_distance_init(z, X, 0)+1);
                if(Y != -1){
                    update_sum(X+1, -get_distance_init(Y, X, 0)-1);
                }
                else update_sum(X+1, -get_distance_init(0, X, 0)-1);
            }
            if(Y != -1){
                update_sum(z+1, get_distance_init(Y, z, 0)+1);
            }
            else update_sum(z+1, get_distance_init(0, z, 0)+1);
            return;
        }
        update_station(2*N, x, (x+y)/2, z);
        update_station(2*N+1, (x+y)/2+1, y, z);
        stations[N].first = min(stations[2*N].first, stations[2*N+1].first);
        if(stations[2*N].first == -1)stations[N].first = stations[2*N+1].first;
        if(stations[2*N+1].first == -1)stations[N].first = stations[2*N].first;
        stations[N].second = max(stations[2*N].second, stations[2*N+1].second);
    }
    bool has_station(int N, int x, int y, int s, int t){
        return first_station(N, x, y, s, t) != -1 || last_station(N, x, y, s, t) != -1;
    }
} A;

void init_trip2(int N, int Q, int C, vector<int> W) {
    A.init(N, C, W);
    // edit this
    return;
}

void toggle2(int G) {
    // edit this
    A.update_station(1, 0, A.n-1, G);
    return;
}

int trip2(int S, int T, int F) {
    // edit this
    int Z = 0;
    if(A.station[T])Z++;
    if(S > T){
        if(S-1>T && A.has_station(1, T+1, S-1, 0, A.n-1)){
            return trip2(A.first_station(1, T+1, S-1, 0, A.n-1), T, A.c)-A.get_sum(A.first_station(1, T+1, S-1, 0, A.n-1)+1)+A.get_sum(A.last_station(1, T+1, S-1, 0, A.n-1)+1)+trip2(S, A.last_station(1, T+1, S-1, 0, A.n-1), F);
        }
        if(A.close_station(S, F) <= T)return Z;
        return Z + 1 + A.get_distance_init(T, A.close_station(S, F), 0);
    }
    if(T-1>S && A.has_station(1, S+1, T-1, 0, A.n-1)){
        return trip2(S, A.first_station(1, S+1, T-1, 0, A.n-1), F)-A.get_sum(A.first_station(1, S+1, T-1, 0, A.n-1)+1)+A.get_sum(A.last_station(1, S+1, T-1, 0, A.n-1)+1)+trip2(A.last_station(1, S+1, T-1, 0, A.n-1), T, A.c);
    }
    if(A.far_station(S, F) >= T)return Z;
    return Z + 1 + A.get_distance_init(A.far_station(S, F), T, 0);
}