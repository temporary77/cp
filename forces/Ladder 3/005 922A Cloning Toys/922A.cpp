#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y;
	scanf("%d%d",&x,&y);
	if ((x-y)&1 && x >= y-1 && y > 0 && (!(y == 1) || x == 0)) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}