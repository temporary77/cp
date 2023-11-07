#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	if (n < m)swap(n,m);
	int max1 = (n+m)/3;
	if (n-m <= max1) {
		printf("%d",max1);
	} else {
		printf("%d",m);
	}



	return 0;
}