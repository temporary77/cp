#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	// t = 10000;
	for (int ti = 0; ti < t; ++ti) {
		long long x, y;
		// x = rand()%10000000+1;
		// y = rand()%10000000+1;
		// x *= 2;
		// y *= 2;
		scanf("%lld%lld",&x,&y);
		long long n;
		if (x > y)n = x+y;
		else if (x == y)n = x;
		else if (x < y)n = y-(x+(y-x)/2)%x;
		printf("%lld\n",n);
		// printf("%lld %lld %lld\n",x,y,n);
		// printf("[%lld %lld]\n",n%x,y%n);
		// if (n%x != y%n)printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	}
	return 0;
}