#include <bits/stdc++.h>
using namespace std;

set<int> st[46][46];
int arr[50][50];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d",&arr[i][j]);
			if (i >= 4 && j >= 4) {
				for (int k = 0; k < 5; ++k) {
					for (int l = 0; l < 5; ++l) {
						st[i-4][j-4].insert(arr[i-k][j-l]);
					}
				}
				if (st[i-4][j-4].size() >= 5) {
					++cnt;
				}
			}
		}
	}
	printf("%d",cnt);

	return 0;
}