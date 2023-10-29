#include <bits/stdc++.h>
using namespace std;

vector<string> vctr(1000);
queue<pair<int,int>> que;
int dx[4] = {0,-1,1,0}, dy[4] = {-1,0,0,1};
char ci[4] = {'0','1','2','3'};
char di[4] = {'L','U','D','R'};

int main() {
	cin.tie(NULL);
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		cin >> vctr[i];
		for (int j = 0; j < m; ++j) {
			if (vctr[i][j] == 'A') {
				que.push({i,j});
			}
		}
	}
	int ans = 1;
	bool check = 0;
	int ex, ey;
	for (;!que.empty();) {
		int t = que.size();
		for (int i = 0; i < t; ++i) {
			int x, y;
			tie(x,y) = que.front();
			que.pop();
			// printf("%d %d\n",x,y);
			int nx, ny;
			for (int j = 0; j < 4; ++j) {
				nx = x+dx[j];
				ny = y+dy[j];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (vctr[nx][ny] == '.') {
						vctr[nx][ny] = ci[j];
						// printf("%d %d %c\n",nx,ny,vctr[nx][ny]);
						que.push({nx,ny});
					} else if (vctr[nx][ny] == 'B') {
						vctr[nx][ny] = ci[j];
						check = 1;
						ex = nx;
						ey = ny;
						goto g;
					}
				}
			}
		}
		++ans;
	}
	g:;
	if (check) {
		printf("YES\n");
	} else {
		printf("NO\n");
		return 0;
	}
	printf("%d\n",ans);
	string str;
	int cx = ex, cy = ey;
	for (;;) {
		int idx = vctr[cx][cy]-'0';
		if (idx == 'A'-'0')break;
		str.push_back(di[idx]);
		if (idx == 0)++cy;
		else if (idx == 1)++cx;
		else if (idx == 2)--cx;
		else if (idx == 3)--cy;
	}
	reverse(str.begin(),str.end());
	cout << str;
	return 0;
}