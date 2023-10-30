#include <bits/stdc++.h>
using namespace std;

int graph[1001][1001];
queue<pair<int,int>> que;
int dx[4] = {0,-1,1,0}, dy[4] = {-1,0,0,1};
char ci[4] = {'R','D','U','L'};

int main() {
	cin.tie(NULL);
	int n, m;
	scanf("%d%d",&n,&m);
	string str;
	int sx, sy;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < m; ++j) {
			if (str[j] == '.') {
				graph[i][j] = INT_MAX;
			} else if (str[j] == 'M') {
				que.push({i,j});
			} else if (str[j] == 'A') {
				graph[i][j] = INT_MAX;
				sx = i;
				sy = j;
			}
		}
	}
	int cur = 0;
	for (;!que.empty();) {
		++cur;
		int t = que.size();
		for (int i = 0; i < t; ++i) {
			int x, y;
			tie(x,y) = que.front();
			que.pop();
			for (int j = 0; j < 4; ++j) {
				int nx = x+dx[j];
				int ny = y+dy[j];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
				if (graph[nx][ny] != INT_MAX)continue;
				graph[nx][ny] = cur;
				que.push({nx,ny});
			}
		}
	}
	graph[sx][sy] = -4;
	cur = 0;
	int ex, ey;
	if (sx == 0 || sx == n-1 || sy == 0 || sy == m-1) {
		ex = sx;
		ey = sy;
		goto g;
	}
	que.push({sx,sy});
	for (;!que.empty();) {
		++cur;
		int t = que.size();
		for (int i = 0; i < t; ++i) {
			int x, y;
			tie(x,y) = que.front();
			que.pop();
			for (int j = 0; j < 4; ++j) {
				int nx = x+dx[j];
				int ny = y+dy[j];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
				if (cur >= graph[nx][ny])continue;
				graph[nx][ny] = j-3;
				if (nx == 0 || nx == n-1 || ny == 0 || ny == m-1) {
					ex = nx;
					ey = ny;
					goto g;
				}
				que.push({nx,ny});
			}
		}
	}
	printf("NO\n");
	return 0;
	g:;
	printf("YES\n");
	string ans;
	for (;;) {
		if (ex == sx && ey == sy)break;
		int idx = graph[ex][ey]*-1;
		ans.push_back(ci[idx]);
		ex += dx[idx];
		ey += dy[idx];
	}
	printf("%d\n",ans.size());
	reverse(ans.begin(),ans.end());
	cout << ans;
	return 0;
}