#include <bits/stdc++.h>
using namespace std;

bool graph[31][31];
bool visited[31][31];
int ans = 0;

void dfs(int x, int y) {
	++ans;
	visited[x][y] = 1;
	if (x > 0 && !graph[x-1][y] && !visited[x-1][y])dfs(x-1,y);
	if (y > 0 && !graph[x][y-1] && !visited[x][y-1])dfs(x,y-1);
	return;
}

int main() {
	int n;
	scanf("%d",&n);
	cin.tie(NULL);
	string str;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < n; ++j) {
			if (str[j] == 'X') {
				graph[i][j] = 1;
			}
		}
	}
	dfs(n-1,n-1);
	printf("%d",ans);
	return 0;
}