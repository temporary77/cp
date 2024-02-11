#include <bits/stdc++.h>
using namespace std;

int lrr[200001];
int rrr[200001];
set<pair<int,int>> st;

int main() {
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		scanf("%d%d",&n,&m);
		cin >> str;
		if (str[n-1] == '0')lrr[n-1] = n;
		else lrr[n-1] = n-1;
		int cur = lrr[n-1];
		for (int i = n-2; i >= 0; --i) {
			if (str[i] == '1')cur = i;
			lrr[i] = cur;
		}
		if (str[0] == '1')rrr[0] = -1;
		else rrr[0] = 0;
		cur = rrr[0];
		for (int i = 1; i < n; ++i) {
			if (str[i] == '0')cur = i;
			rrr[i] = cur;
		}
		// for (int i = 0; i < n; ++i) {
		// 	printf("%d ",lrr[i]);
		// }
		// printf("\n");
		// for (int i = 0; i < n; ++i) {
		// 	printf("%d ",rrr[i]);
		// }
		// printf("\n");
		int futile = 0;
		for (int i = 0; i < m; ++i) {
			int l, r;
			scanf("%d%d",&l,&r);
			--l; --r;
			if (lrr[l] > rrr[r]) {
				futile = 1;
				continue;
			}
			st.insert({lrr[l],rrr[r]});
		}
		printf("%d\n",st.size()+futile);
		st.clear();
	}
	return 0;
}