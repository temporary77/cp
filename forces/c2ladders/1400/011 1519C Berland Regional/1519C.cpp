#include <bits/stdc++.h>
using namespace std;

vector<long long> vctr[200001];
int u[200001];
long long ans[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&u[i]);
		}
		for (int i = 1; i <= n; ++i) {
			vctr[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			int s;
			scanf("%d",&s);
			vctr[u[i]].push_back(s);
		}
		for (int i = 1; i <= n; ++i) {
			sort(vctr[i].begin(),vctr[i].end(),greater<long long>());
			for (int j = 1; j < vctr[i].size(); ++j) {
				vctr[i][j] += vctr[i][j-1];
			}
		}
		fill(ans+1,ans+n+1,0);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= vctr[i].size(); ++j) {
				ans[j] += vctr[i][vctr[i].size()-(vctr[i].size()%j)-1];
				// printf("%d %d\n",j,vctr[i].size()-(vctr[i].size()%j));
			}
		}
		for (int i = 1; i <= n; ++i) {
			printf("%lld ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}