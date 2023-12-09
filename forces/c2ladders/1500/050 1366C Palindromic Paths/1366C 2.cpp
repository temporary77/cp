#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		scanf("%d%d",&n,&m);
		vector<vector<int>> vctr(30,vector<int>(2,0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int a;
				scanf("%d",&a);
				++vctr[i+j][a];
			}
		}
		continue;
		int ans = 0;
		for (int i = 0; i < (n+m-1)/2; ++i) {
			ans += min(vctr[i][0]+vctr[n+m-2-i][0],vctr[i][1]+vctr[n-m-2-i][1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}