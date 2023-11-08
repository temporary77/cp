#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	string str;
	char c;
	for (;;) {
		cin >> str;
		if (!ispunct(str[str.size()-1])) {
			c = str[str.size()-1];
			continue;
		}
		if (str.size() > 1)c = str[str.size()-2];
		c = tolower(c);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
			printf("YES");
		} else {
			printf("NO");
		}
		return 0;
	}
	return 0;
}