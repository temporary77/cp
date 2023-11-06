#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	long long n;
	scanf("%lld",&n);
	string str;
	cin >> str;
	long long l = 0;
	for (; l < n-1; ++l) {
		if (str[l+1] != str[0])break;
	}
	long long r = n-1;
	for (; r > 0; --r) {
		if (str[r-1] != str[n-1])break;
	}
	long long ans;
	if (l >= r) {
		ans = n*(n+1)/2;
	} else if (str[0] == str[n-1]) {
		ans = (l+2)*(n-r+1);
	} else if (str[0] != str[n-1]) {
		ans = (l+1)+(n-r)+1;
	}
	printf("%lld",ans%998244353);
	return 0;
}