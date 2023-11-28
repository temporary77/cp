#include <bits/stdc++.h>
using namespace std;

vector<int> vctr[2];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			vctr[i&1].push_back(a);
		}
		sort(vctr[0].begin(),vctr[0].end());
		sort(vctr[1].begin(),vctr[1].end());
		for (int i = 0; i < n-1; ++i) {
			if (vctr[i&1][i/2] > vctr[(i&1)^1][(i+1)/2]) {
				// printf("%d %d\n",vctr[i&1][i/2],vctr[(i&1)^1][i/2]);
				printf("NO\n");
				goto g;
			}
		}
		printf("YES\n");
		g:;
		vctr[0].clear();
		vctr[1].clear();
	}
	return 0;
}