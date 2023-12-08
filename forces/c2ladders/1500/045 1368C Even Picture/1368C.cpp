#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	printf("%d\n",4+3*n);
	printf("0 0\n");
	for (int i = -1; i < n; ++i) {
		printf("%d %d\n",1+i,2+i);
		printf("%d %d\n",2+i,2+i);
		printf("%d %d\n",2+i,1+i);
	}
	return 0;
}