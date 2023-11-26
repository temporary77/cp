#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int amax = floor(sqrt(2*n-1));
		printf("%d\n",(amax-1)/2);
	}
	return 0;
}