#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		if (n&1) {
			int x, y, z;
			scanf("%d%d%d",&x,&y,&z);
			if (y+z != 0) {
				printf("%d %d %d ",-(y+z),x,x);
			} else if (x+z != 0) {
				printf("%d %d %d ",y,-(x+z),y);
			} else if (x+y != 0) {
				printf("%d %d %d ",z,z,-(x+y));
			}
			for (int i = 3; i < n; i += 2) {
				scanf("%d%d",&x,&y);
				printf("%d %d ",-y,x);
			}
		} else {
			int x, y;
			for (int i = 0; i < n; i += 2) {
				scanf("%d%d",&x,&y);
				printf("%d %d ",-y,x);
			}
		}
		printf("\n");
	}
	return 0;
}