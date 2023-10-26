#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	vector<int> vctr;
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d",&k);
		vctr.push_back(k);
	}
	sort(vctr.begin(),vctr.end());
	for (auto it = vctr.begin(); it != vctr.end(); ++it) {
		printf("%d ",*it);
	}
	return 0;
}