#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int a, b;
		scanf("%d%d",&a,&b);
		if (a >= b) {
			printf("%d\n",a-b);
			continue;
		}
		int ans = 0;
		for (int i = 0; i < 20; ++i) {
			// printf("%d %d %d\n",a,b,i);
			if (a&(1 << i) && !(b&(1 << i))) {
				printf("%d %d %d\n",i,a,b);
				for (int j = i+1; j < 20; ++j) {
					if (!(a&(1 << j)) && b&(1 << j)) {
						ans += (1 << i);
						a += (1 << i);
						break;
					}
				}
			}
		}
		if (a >= b) {
			ans += a-b;
			printf("%d\n",ans);
			continue;	
		}
		++ans;
		a |= b;
		ans += a-b;
		printf("%d\n",ans);
	}
	return 0;
}

/*
1
3
2
1
23329
*/