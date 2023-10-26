#include <bits/stdc++.h>
using namespace std;

int arr[5];
int dist[101][5];
bool visited[101][5];

int main() {
	cin.tie(nullptr);
	//freopen("test_input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		char c;
		int x;
		vector<int> vctr[5];
		unordered_map<int,vector<int>> mp;
		vector<pair<int,int>> graph[101][5];
		string str;
		getline(cin,str);
		for (int i = 0; i < n; ++i) {
			getline(cin,str);
			//cout << str << endl;
			for (int j = 0; j <= str.size(); ++j) {
				if (str[j] == ' ' || j == str.size()) {
					//printf("%d <<\n",x);
					vctr[i].push_back(x);
					mp[x].push_back(i);
					int js = vctr[i].size()-1;
					if (js >= 1) {
						graph[vctr[i][js]][i].push_back({vctr[i][js-1],i});
						//printf("%d <<<<\n",vctr[i][js-1]);
						graph[vctr[i][js-1]][i].push_back({vctr[i][js],i});
					}
					x = 0;
				} else if (str[j] >= 48 && str[j] <= 57) {
					x *= 10;
					x += str[j]-48;
				}
			}
		}
		for (auto it : mp) {
			for (int i = 0; i < it.second.size(); ++i) {
				for (int j = i+1; j < it.second.size(); ++j) {
					graph[it.first][it.second[i]].push_back({it.first,it.second[j]});
					graph[it.first][it.second[j]].push_back({it.first,it.second[i]});
				}
			}
		}
		priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[i][j] = INT_MAX;
				visited[i][j] = 0;
			}
		}
		for (auto it : mp[0]) {
			dist[0][it] = 0;
			pq.push({0,{0,it}});
		}
		int anse = -1;
		int dd = 0;
		for (;!pq.empty();) {
			int d = pq.top().first;
			int f = pq.top().second.first;
			int e = pq.top().second.second;
			pq.pop();
			if (visited[f][e] == 1)continue;
			visited[f][e] = 1;
			if (f == k) {
				anse = e;
				break;
			}
			for (auto it : graph[f][e]) {
				int w;
				if (it.second == e) {
					w = abs(it.first-f)*arr[e];
				} else {
					w = 60;
				}
				if (dist[it.first][it.second] > dist[f][e]+w && visited[it.first][it.second] == 0) {
					dist[it.first][it.second] = dist[f][e]+w;
					pq.push({dist[it.first][it.second],{it.first,it.second}});
				}
			}
		}
		if (anse == -1)printf("IMPOSSIBLE\n");
		else printf("%d\n",dist[k][anse]);
	}
	return 0;
}

/*
1
5 97
100 100 100 100 100
0 99
99 1
1 98
98 2
2 97
2 0
10 5
0 1 3 5 7 9 11 13 15 20 99
4 13 15 19 20 25 30
2 30
10 1
0 5 10 12 14 20 25 30
2 4 6 8 10 12 14 22 25 28 29
3 50
10 50 100
0 10 30 40
0 20 30
0 20 50
1 1
2
0 2 4 6 8 10
*/