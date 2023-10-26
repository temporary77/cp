#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	scanf("%I64d",&n);
	printf("%I64d",2*(n*(n-1)*n/2-(n-1)*n*(2*n-1)/6)-2);
	return 0;
}