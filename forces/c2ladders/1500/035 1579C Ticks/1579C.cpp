#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

bool grid[11][20];
bool visited[11][20];
pair<int,int> arr[11][20];

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		int n, m, k;
		scanf("%d%d%d",&n,&m,&k);
		int cnt = 0;
		fill(arr[0],arr[0]+m,(pair<int,int>){0,0});
		for (int i = 0; i < n; ++i) {
			cin >> str;
			for (int j = 0; j < m; ++j) {
				visited[i][j] = false;
				if (str[j] == '*') {
					grid[i][j] = true;
					++cnt;
					if (min(arr[i][j].f,arr[i][j].s) >= k) {
						// printf("%d %d %d %d\n",i,j,arr[i][j].f,arr[i][j].s);
						if (!visited[i][j]) {
							--cnt;
							visited[i][j] = true;
						}
						for (int d = 1; d <= min(arr[i][j].f,arr[i][j].s); ++d) {
							if (grid[i-d][j-d] && !visited[i-d][j-d] && j-d >= 0) {
								--cnt;
								visited[i-d][j-d] = true;
							}
							if (grid[i-d][j+d] && !visited[i-d][j+d] && j+d < m) {
								--cnt;
								visited[i-d][j+d] = true;
							}
						}
					}
					if (i == n-1)continue;
					if (j > 0) {
						arr[i+1][j-1].s = arr[i][j].s+1;
					}
					if (j < m-1) {
						arr[i+1][j+1].f = arr[i][j].f+1;
					}
				} else {
					grid[i][j] = false;
					if (i == n-1)continue;
					if (j > 0) {
						arr[i+1][j-1].s = 0;
					}
					if (j < m-1) {
						arr[i+1][j+1].f = 0;
					}
				}
			}
		}
		// printf("%d\n",cnt);
		if (cnt == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}