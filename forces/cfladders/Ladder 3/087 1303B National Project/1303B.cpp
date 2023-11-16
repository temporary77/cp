#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, g, b;
		scanf("%d%d%d",&n,&g,&b);
		int r = (n+1)/2;
		// if (g >= b || r <= (n/(g+b))*g+min(n%(g+b),g))printf("%lld\n",(long long)n);
		// else printf("%lld\n",r+b*((long long)(r-1)/g));
		printf("%lld\n",max((long long)n,(g+b)*(long long)((r-1)/g)+((r-1)%g+1)));
	}
	return 0;
}