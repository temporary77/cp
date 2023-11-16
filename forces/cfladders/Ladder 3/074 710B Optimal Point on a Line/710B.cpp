#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

int main() {
	int n;
	scanf("%d",&n);
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		vctr.push_back(k);
	}
	sort(vctr.begin(),vctr.end());
	printf("%d",vctr[(n-1)/2]);
	return 0;
}