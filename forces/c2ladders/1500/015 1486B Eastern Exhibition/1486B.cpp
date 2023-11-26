#include <bits/stdc++.h>
using namespace std;

vector<int> xvctr, yvctr;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d",&x,&y);
			xvctr.push_back(x);
			yvctr.push_back(y);
		}
		sort(xvctr.begin(),xvctr.end());
		sort(yvctr.begin(),yvctr.end());
		int xans = xvctr[n/2]-xvctr[(n-1)/2]+1;
		int yans = yvctr[n/2]-yvctr[(n-1)/2]+1;
		printf("%lld\n",(long long)xans*yans);
		xvctr.clear();
		yvctr.clear();
	}
	return 0;
}