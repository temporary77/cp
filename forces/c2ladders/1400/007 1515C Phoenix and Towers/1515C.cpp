#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vctr;
int ans[100001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, m, x;
		scanf("%d%d%d",&n,&m,&x);
		int idx = vctr.size();
		for (int i = 0; i < n; ++i) {
			int k;
			scanf("%d",&k);
			vctr.push_back({k,i});
		}
		sort(vctr.begin()+idx,vctr.end());
		for (int i = 0; i < n; ++i) {
			ans[vctr[idx+i].second] = i%m+1;
		}
		printf("YES\n");
		for (int i = 0; i < n; ++i) {
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}