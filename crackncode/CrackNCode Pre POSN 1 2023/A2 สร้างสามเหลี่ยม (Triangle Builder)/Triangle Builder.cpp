#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	long long sum = 0;
	for (int a = 0; a <= n; ++a) {
		for (int b = 0; b <= m; ++b) {
			for (int c = 0; c <= n; ++c) {
				for (int d = 0; d <= m; ++d) {
					for (int e = 0; e <= n; ++e) {
						for (int f = 0; f <= m; ++f) {
							if ((a == c && b == d) || (a == e && b == f) || (c == e && d == f)) {
								continue;
							} else {
								sum += abs(a*d+c*f+e*b-b*c-d*e-f*a);
							}
						}
					}
				}
			}
		}
	}
	printf("%lld",sum/6);
	return 0;
}