#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int x = 1;
	string str;
	cin >> str;
	for (auto c : str) {
		if (c == 'A') {
			x = (5-x)%3+1;
		} else if (c == 'B') {
			x = (4-x)%3+1;
		} else if (c == 'C') {
			x = 4-x;
		}
	}
	printf("%d",x);
	return 0;
}