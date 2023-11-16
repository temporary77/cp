#include <bits/stdc++.h>
using namespace std;

stack<long long> stck;

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= sqrt(n); ++i) {
		if (!(n%i)) {
			printf("%lld ",(long long)(2+n-n/i)*i/2);
			if (n/i != i) {
				stck.push((long long)(2+n-i)*(n/i)/2);
			}
		}
	}
	for (;!stck.empty();) {
		printf("%lld ",stck.top());
		stck.pop();
	}
	return 0;
}