#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

int main() {
	int n, m, k;
	scanf("%d%d%d",&n,&m,&k);
	int prev;
	scanf("%d",&prev);
	int x;
	for (int i = 1; i < n; ++i) {
		scanf("%d",&x);
		vctr.push_back(x-prev-1);
		prev = x;
	}
	sort(vctr.begin(),vctr.end());
	long long sum = 0;
	for (int i = 0; i < n-k; ++i) {
		sum += vctr[i];
	}
	printf("%lld",n+sum);
	return 0;
}