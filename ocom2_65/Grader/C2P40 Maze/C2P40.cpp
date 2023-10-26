#include <bits/stdc++.h>
using namespace std;

bool arr[10000][10000];
int ans = 0;
int min1 = INT_MAX;
int max1 = INT_MIN;
int n, m;
int dirx[4] = {0,-1,1,0}, diry[4] = {-1,0,0,1};

void recursion(int k, int a, int b) {
	if (a == n-1 && b == m-1) {
		++ans;
		min1 = min(min1,k);
		max1 = max(max1,k);
		return;
	}
	++k;
	arr[a][b] = 1;
	int x, y;
	for (int i = 0; i < 4; ++i) {
		x = a+dirx[i];
		y = b+diry[i];
		if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == 0) {
			recursion(k,x,y);
		}
	}
	arr[a][b] = 0;
	return;
}

int main() {
	scanf("%d%d",&n,&m);
	string str;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < m; ++j) {
			if (str[j] == 'x') {
				arr[i][j] = 1;
			}
		}
	}
	recursion(1,0,0);
	printf("%d %d %d",ans,max1,min1);
	return 0;
}