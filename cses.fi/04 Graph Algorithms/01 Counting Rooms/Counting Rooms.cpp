#include <bits/stdc++.h>
using namespace std;

int n, m;
bool unvisited[1002][1002];
int dx[4] = {0,-1,1,0}, dy[4] = {-1,0,0,1};

void dfs(int x, int y) {
	unvisited[x][y] = 0;
	for (int i = 0; i < 4; ++i) {
		if (unvisited[x+dx[i]][y+dy[i]])dfs(x+dx[i],y+dy[i]);
	}
	return;
}

int main() {
	cin.tie(NULL);
	scanf("%d%d",&n,&m);
	string str;
	for (int i = 1; i <= n; ++i) {
		cin >> str;
		for (int j = 1; j <= m; ++j) {
			if (str[j-1] == '.')unvisited[i][j] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (unvisited[i][j]) {
				++ans;
				dfs(i,j);
			}
		}
	}
	printf("%d",ans);
	return 0;
}