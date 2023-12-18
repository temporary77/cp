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
		int ans = INT_MAX;
		for (int bi = b; bi <= 2*b; ++bi) {
			int ansi = bi-b;
			int ai = a;
			for (int i = 0; i < 20; ++i) {
				if ((ai&(1 << i)) && !(bi&(1 << i))) {
					int cur = 1 << i;
					for (int j = i-1; j >= 0; --j) {
						if (ai&(1 << j)) {
							cur -= 1 << j;
						}
					}
					ansi += cur;
					ai += cur;
				}
			}
			// printf("%d %d %d\n",ansi,a,b);
			if (ai != bi) {
				++ansi;
				ansi += (ai|bi)-bi;
			}
			ans = min(ans,ansi);
		}
		printf("%d\n",ans);
	}
	return 0;
}