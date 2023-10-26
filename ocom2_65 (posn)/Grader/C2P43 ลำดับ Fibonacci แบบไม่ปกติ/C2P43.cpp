#include <bits/stdc++.h>
using namespace std;

long long recursion(long long n, long long a, long long b) {
	if (n == 0) return a;
	return recursion(n-1,b,a+b);
}

int main() {
	long long n, a, b;
	scanf("%lld%lld%lld",&n,&a,&b);
	long long ans = recursion(n,a,b);
	printf("%lld",ans);
	return 0;
}