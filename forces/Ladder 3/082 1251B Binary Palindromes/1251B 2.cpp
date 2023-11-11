#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int q;
	scanf("%d",&q);
	for (int qi = 0; qi < q; ++qi) {
		int n;
		scanf("%d",&n);
		string str;
		bool check = 0;
		int badstrings = 0;
		int cnt0;
		for (int i = 0; i < n; ++i) {
			cin >> str;
			if (str.size()&1) {
				check = 1;
				continue;
			}
			cnt0 = 0;
			for (auto it : str) {
				if (it == '0')++cnt0;
			}
			if (cnt0&1) {
				++badstrings;
			}
		}
		if (badstrings&1 && !check) {
			printf("%d\n",n-1);
		} else {
			printf("%d\n",n);
		}
	}
	return 0;
}