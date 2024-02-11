#include <bits/stdc++.h>
using namespace std;

int qs[200001];
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
		for (int i = 1; i < n; ++i) {
			qs[i] = str[i]-str[i-1];
			if (qs[i] == -1)qs[i] = 2;
			qs[i] += qs[i-1];
		}
		lrr[0] = 0;
		int cur = 0;
		for (int i = 1; i < n; ++i) {
			if (str[i-1] != '0')cur = i;
			lrr[i] = cur;
		}
		rrr[n-1] = n-1;
		cur = n-1;
		for (int i = n-2; i >= 0; --i) {
			if (str[i+1] != '1')cur = i;
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
		// for (int i = 0; i < n; ++i) {
		// 	printf("%d ",qs[i]);
		// }
		// printf("\n");
		int futile = 0;
		for (int i = 0; i < m; ++i) {
			int l, r;
			scanf("%d%d",&l,&r);
			--l; --r;
			if (qs[r]-qs[l] == 0 || qs[r]-qs[l] == 1) {
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