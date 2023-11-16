#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, c, d;
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	int x = b-c;
	int y = a-d;
	int min1 = min(0,min(min(b-c,a-d),a+b-c-d));
	int max1 = max(0,max(max(b-c,a-d),a+b-c-d));
	if (max1-min1 >= n)printf("0");
	else printf("%lld",n*(long long)(n-(max1-min1)));
	return 0;
}