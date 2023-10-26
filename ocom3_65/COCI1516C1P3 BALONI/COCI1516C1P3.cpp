#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

int main() {
	int n;
	scanf("%d",&n);
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		auto it = lower_bound(vctr.begin(),vctr.end(),k+1);
		if (it == vctr.end()) {
			vctr.push_back(k);
		} else if (*it == k+1) {
			*it = k;
		} else {
			//printf("> %d %d\n",*it,it-vctr.begin());
			vctr.push_back(k);
			rotate(upper_bound(vctr.begin(),vctr.end()-1,k),vctr.end()-1,vctr.end());
		}
	}
	printf("%lu",vctr.size());
	return 0;
}