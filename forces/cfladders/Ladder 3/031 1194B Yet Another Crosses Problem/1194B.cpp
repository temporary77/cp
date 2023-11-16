#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int q;
	scanf("%d",&q);
	for (int qi = 0; qi < q; ++qi) {
		int n, m;
		scanf("%d%d",&n,&m);
		string str;
		bool graph[n][m] = {false};
		int rowsum[n] = {0};
		int colsum[m] = {0};
		for (int i = 0; i < n; ++i) {
			cin >> str;
			rowsum[i] = 0;
			for (int j = 0; j < m; ++j) {
				if (str[j] == '.') {
					graph[i][j] = 1;
					++rowsum[i];
					++colsum[j];
				} else {
					graph[i][j] = 0;
				}
			}
		}
		int ans = INT_MAX;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ans = min(ans,rowsum[i]+colsum[j]-(graph[i][j] ? 1 : 0));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}