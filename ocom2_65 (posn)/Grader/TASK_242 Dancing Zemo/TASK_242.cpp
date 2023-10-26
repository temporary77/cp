#include <bits/stdc++.h>
using namespace std;

int arr[10005][6];
//  0     1     2     3     4     5
// L U   L R   L D   U R   U D   R D
int ms[4][3] = {{0,1,2},{0,3,4},{1,3,5},{2,4,5}};

int getmax(int l, int k) {
	int og = 5-k;
	int max1 = -2;
	for (int i = 0; i < 6; ++i) {
		if (i == k)continue;
		if (i == og) {
			max1 = max(max1,arr[l][i]+1);
			continue;
		}
		//printf("passed %d %d %d\n",i,max1,arr[l][i]);
		max1 = max(max1,arr[l][i]);
	}
	//printf("%d %d %d\n",l,k,max1);
	return max1;
}

int main() {
	cin.tie(nullptr);
	//freopen("test_input.txt","r",stdin);
	int n, m;
	scanf("%d",&n);
	for (int i = 0; i < 6; ++i) {
		arr[0][i] = -2;
	}
	arr[0][1] = 0;
	for (int t = 0; t < n; ++t) {
		string str;
		cin >> str;
		m = str.size();
		char c;
		int d;
		for (int i = 1; i <= m; ++i) {
			c = str[i-1];
			if (c == 'L')d = 0;
			else if (c == 'U')d = 1;
			else if (c == 'R')d = 2;
			else if (c == 'D')d = 3;
			for (int j = 0; j < 3; ++j) {
				//printf("%d %d\n",i,ms[d][j]);
				arr[i][ms[d][j]] = getmax(i-1,5-ms[d][j]);
				arr[i][5-ms[d][j]] = -2;
			}
		}
		/*for (int i = 0; i <= m; ++i) {
			for (int j = 0; j < 6; ++j) {
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}*/
		printf("%d\n",getmax(m,-1));
	}
	return 0;
}