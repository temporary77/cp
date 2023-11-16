#include <bits/stdc++.h>
using namespace std;

int f[10];

int main() {
	cin.tie(NULL);
	int n;
	scanf("%d",&n);
	string str;
	cin >> str;
	for (int i = 1; i <= 9; ++i) {
		scanf("%d",&f[i]);
	}
	bool check = 0;
	for (int i = 0; i < n; ++i) {
		int x = str[i]-'0';
		if (!check) {
			if (f[x] > x) {
				check = 1;
				str[i] = f[x]+'0';
			}
		} else if (check) {
			if (f[x] < x) {
				break;
			}
			str[i] = f[x]+'0';
		}
	}
	cout << str;
	return 0;
}