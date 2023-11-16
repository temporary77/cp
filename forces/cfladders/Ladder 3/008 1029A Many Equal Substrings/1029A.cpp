#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int n, k;
	scanf("%d%d",&n,&k);
	string str;
	cin >> str;
	cout << str;
	int idx = 0;
	for (int i = n-2; i >= 0; --i) {
		int r = n-1;
		for (int j = i; j >= 0; --j) {
			if (str[j] != str[r]) {
				break;
			}
			--r;
			if (j == 0) {
				idx = i+1;
				goto g;
			}
		}
	}
	g:;
	string str2 = str.substr(idx);
	for (int i = 0; i < k-1; ++i) {
		cout << str2;
	}
	return 0;
}