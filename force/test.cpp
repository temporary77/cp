#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 0;
	for (int i = 1; i <= 31; ++i) {
		for (int j = 1; j <= 31; ++j) {
			if (i == 16 || j == 16)continue;
			++t;
			printf("%d %d\n",i,j);
		}
	}
	printf("%d",t);
	return 0;
}