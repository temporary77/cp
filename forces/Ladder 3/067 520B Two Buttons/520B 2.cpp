#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int ans = 0;
	for (;m > n;) {
		++ans;
		if (m&1)++m;
		else m >>= 1;
	}
	printf("%d",ans+n-m);
	return 0;
}