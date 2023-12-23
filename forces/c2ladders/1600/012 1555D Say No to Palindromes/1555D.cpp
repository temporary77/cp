#include <bits/stdc++.h>
using namespace std;

int qs[6][200001];

int main() {
	cin.tie(NULL);
	int n, m;
	scanf("%d%d",&n,&m);
	string str;
	cin >> str;
	for (int j = 0; j < 3; ++j) {
		for (int i = 1; i <= n; ++i) {
			qs[j][i] = qs[j][i-1];
			qs[j+3][i] = qs[j+3][i-1];
			if (str[i-1] != 'a'+(i+j)%3)++qs[j][i];
			if (str[i-1] != 'a'+((int)3e5-i+j)%3)++qs[j+3][i];
		}
	}
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d",&l,&r);
		int res = INT_MAX;
		for (int j = 0; j < 6; ++j) {
			res = min(res,qs[j][r]-qs[j][l-1]);
		}
		printf("%d\n",res);
	}
	return 0;
}