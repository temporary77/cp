#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	long long pos = 0, neg = 0;
	long long curp = 0, curn = 0;
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		if (k > 0) {
			++curp;
		} else if (k < 0) {
			swap(curp,curn);
			++curn;
		}
		pos += curp;
		neg += curn;
	}
	printf("%lld %lld",neg,pos);
	return 0;
}