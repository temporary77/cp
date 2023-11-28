#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		cin >> str;
		int max1 = 0;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				int cur = 0;
				bool parity = 1;
				for (auto it : str) {
					if (parity) {
						if (it-'0' == i) {
							++cur;
							parity ^= 1;
						}
					} else {
						if (it-'0' == j) {
							++cur;
							parity ^= 1;
						}
					}
				}
				if (i != j && cur&1)--cur;
				max1 = max(max1,cur);
			}
		}
		printf("%d\n",str.size()-max1);
	}
	return 0;
}