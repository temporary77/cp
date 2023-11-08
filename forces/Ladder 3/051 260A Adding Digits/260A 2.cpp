#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, n;
	scanf("%d%d%d",&a,&b,&n);
	int x = b-((10*a-1)%b+1);
	if (x < 10) {
		printf("%d%d",a,x);
		for (int i = 1; i < n; ++i) {
			printf("0");
		}
	} else {
		printf("-1");
	}
	return 0;
}