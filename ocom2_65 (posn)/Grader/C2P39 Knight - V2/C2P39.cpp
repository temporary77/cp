#include <bits/stdc++.h>
using namespace std;

bool arr[10000][10000];
int ans = 0;
int dirx[8] = {-1,1,-2,2,-2,2,-1,1}, diry[8] = {-2,-2,-1,-1,1,1,2,2};
int m, n;

void recursion(int k, int a, int b) {
	if (k == 1) {
		++ans;
		return;
	}
	int x, y;
	--k;
	arr[a][b] = 1;
	for (int i = 0; i < 8; ++i) {
		x = a+dirx[i];
		y = b+diry[i];
		if (x >= 0 && x < m && y >= 0 && y < n && arr[x][y] == 0) {
			recursion(k,x,y);
		}
	}
	arr[a][b] = 0;
	return;
}

int main() {
	int a, b;
	scanf("%d%d%d%d",&m,&n,&a,&b);
	recursion(m*n,a,b);
	printf("%d",ans);
	return 0;
}