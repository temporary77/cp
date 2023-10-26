#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	bool cp = 0, smll = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] >= 97) {
			smll = 1;
		} else {
			cp = 1;
		}
		if (cp && smll) {
			printf("Mix");
			return 0;
		}
	}
	if (cp) {
		printf("All Capital Letter");
	} else {
		printf("All Small Letter");
	}
	return 0;
}