#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	long long a, b, c;
	scanf("%d%lld%lld%lld",&n,&a,&b,&c);
	if (n%4 == 0) {
		printf("0");
	} else if (n%4 == 1) {
		printf("%lld",min(min(c,a+b),3*a));
	} else if (n%4 == 2) {
		printf("%lld",min(min(2*a,b),2*c));
	} else if (n%4 == 3) {
		printf("%lld",min(min(a,b+c),3*c));
	}
	return 0;
}