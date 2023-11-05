#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	if (n == 1) {
		printf("1");
		return 0;
	}
	if (m-1 >= n-m) {
		printf("%d",m-1);
	} else {
		printf("%d",m+1);
	}
	return 0;
}