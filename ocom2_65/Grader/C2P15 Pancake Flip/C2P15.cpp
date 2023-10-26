#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q, k;
	scanf("%d%d",&n,&q);
	vector<int> vctr;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		vctr.push_back(k);
	}
	for (int i = 0; i < q; ++i) {
		scanf("%d",&k);
		reverse(vctr.begin()+k,vctr.end());
	}
	for (auto it = vctr.begin(); it != vctr.end(); ++it) {
		printf("%d ",*it);
	}
	return 0;
}