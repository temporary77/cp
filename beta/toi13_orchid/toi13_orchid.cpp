#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

int main() {
	int n;
	scanf("%d",&n);
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		auto it = upper_bound(vctr.begin(),vctr.end(),k);
		if (it == vctr.end()) {
			vctr.push_back(k);
		} else {
			*it = k;
		}
	}
	printf("%d",n-vctr.size());
	return 0;
}