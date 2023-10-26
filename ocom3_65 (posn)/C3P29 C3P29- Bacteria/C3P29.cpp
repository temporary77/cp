#include <bits/stdc++.h>
using namespace std;

int graph[5][5][5];
int rooms[5];
int connected[5][25];
bool visited[5][25];
int dx[4] = {0,-1,1,0}, dy[4] = {1,0,0,-1};
set<pair<int,int>> graph2[5][25];
int n, m, f;

void dfs(int r, int j, int k, int i) {
	if (j < 0 || j >= n || k < 0 || k >= m)return;
	if (graph[j][k][i] != -1)return;
	graph[j][k][i] = r;
	for (int ii = 0; ii < 4; ++ii) {
		dfs(r,j+dx[ii],k+dy[ii],i);
	}
	return;
}

int main() {
	//freopen("test_input.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&f);
	char c;
	//cout << 1/0;
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < n; ++j) {
			//getline(cin >> ws,str);
			//cout << str << endl;
			//scanf(" %c",&c);
			//if (c == ' ')cout << "HADS";
			for (int k = 0; k < m; ++k) {
				scanf(" %c",&c);
				if (c == '.') {
					graph[j][k][i] = -1;	
					//printf("%d%d%d\n",j,k,i);
				}
				//printf("%d ",graph[j][k][i]);
			}
			//printf("\n");
		}
	}	
	//cout << 1/0;
	for (int i = 0; i < f; ++i) {
		int r = 1;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (graph[j][k][i] == -1) {
					dfs(r,j,k,i);
					++r;
					++rooms[i];
				}
				//printf("%d ",graph[j][k][i]);
			}
			//printf("\n");
		}
	}
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (graph[j][k][i] != 0) {
					if (i) {
						if (graph[j][k][i-1] != 0) {
							graph2[i][graph[j][k][i]].insert({i-1,graph[j][k][i-1]});
							//graph2[i-1][graph[j][k][i-1]].insert({i,graph[j][k][i]});
						}
					}
					if (i < f-1) {
						if (graph[j][k][i+1] != 0) {
							graph2[i][graph[j][k][i]].insert({i+1,graph[j][k][i+1]});
							//graph2[i+1][graph[j][k][i+1]].insert({i,graph[j][k][i]});
						}
					}
				}
			}
		}
	}
	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;			
	for (int i = 0; i < f; ++i) {
		for (int j = 1; j <= rooms[i]; ++j) {
			connected[i][j] = graph2[i][j].size();
			//printf("%d %d %d <\n",connected[i][j],i,j);
			pq.push({connected[i][j],i,j});
		}
	}
	int ans = 0;
	for (;!pq.empty();) {
		int cn, fl, rm;
		tie(cn,fl,rm) = pq.top();
		pq.pop();
		if (visited[fl][rm] == 1)continue;
		//printf("%d %d\n",fl,rm);
		visited[fl][rm] = 1;
		++ans; 
		for (auto it : graph2[fl][rm]) {
			if (visited[it.first][it.second] == 1)continue;
			visited[it.first][it.second] = 1;
			for (auto it2 : graph2[it.first][it.second]) {
				if (visited[it2.first][it2.second] == 1)continue;
				--connected[it2.first][it2.second];
				pq.push({connected[it2.first][it2.second],it2.first,it2.second});
			}
		}
	}
	printf("%d",ans);
	return 0;
}