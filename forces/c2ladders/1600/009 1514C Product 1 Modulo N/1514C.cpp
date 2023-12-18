#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

int main() {
	int n;
	scanf("%d",&n);
	long long cur = 1;
	for (int i = 2; i <= n; ++i) {
		if (__gcd(n,i) == 1) {
			cur *= i;
			cur %= n;
			vctr.push_back(i);
		}
	}
	int exception = cur;
	printf("%d\n1 ",vctr.size()+(exception == 1 ? 1 : 0));
	for (auto it : vctr) {
		if (it == exception)continue;
		printf("%d ",it);
	}
	return 0;
}