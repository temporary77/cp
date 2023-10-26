#include <bits/stdc++.h>
using namespace std;

int map1[3500][3500];

int main() {
	//freopen("test_input.txt","r",stdin);
	int n, m;
	scanf("%d%d",&n,&m);
	int k, max1 = -1;
	for (int i = 0; i < n; ++i) { 
		for (int j = 0; j < m; ++j) {
			scanf("%d",&k);
			if (k == 0) {
				map1[i][j] = 0;//			printf("%d ",map1[i][j]);
				continue;
			}
			if (i == 0 || j == 0) {
				map1[i][j] = 1;//			printf("%d ",map1[i][j]);
				continue;
			}
			map1[i][j] = min(min(map1[i-1][j-1],map1[i][j-1]),map1[i-1][j])+1;
			max1 = max(max1,map1[i][j]);
			//printf("%d ",map1[i][j]);
		}
		//printf("\n");
	}
	printf("%d",max1);
	return 0;
}