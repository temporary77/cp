#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		vctr.push_back(k);
	}
	sort(vctr.begin(),vctr.end());
	for (int i = 0; i < m; ++i) {
		scanf("%d",&k);
		printf("%d ",upper_bound(vctr.begin(),vctr.end(),k)-vctr.begin());
	}
	return 0;
}