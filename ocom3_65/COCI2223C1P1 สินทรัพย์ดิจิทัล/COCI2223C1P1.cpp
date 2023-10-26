#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	int n, r, s;
	scanf("%d%d%d",&n,&r,&s);
	string str;
	int max1, min1;
	for (int i = 0; i < n; ++i) {
		max1 = -1;
		for (int j = r; j >= 1; --j) {
			cin >> str;
			for (int k = 0; k < s; ++k) {
				if (str[k] == '#') {
					if (max1 == -1)max1 = j;
					min1 = j;
				}
			}
		}
		printf("%d\n",max1-min1);
	}

	return 0;
}