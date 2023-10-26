#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < 2*n-1; ++i) {
		for (int j = 0; j < 2*n-1; ++j) {
			if (j == 0 || j == 2*n-2 || i == j) {
				printf("#");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
 
 
	return 0;
}