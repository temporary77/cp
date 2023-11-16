#include <bits/stdc++.h>
using namespace std;

string s[3];

int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	int idx = 0;
	for (auto it : str) {
		if (it == '0') {
			s[idx].push_back('0');
		} else if (it == '1') {
			s[1].push_back('1');
		} else if (it == '2') {
			idx = 2;
			s[idx].push_back('2');
		}
	}
	cout << s[0] << s[1] << s[2];
	return 0;
}